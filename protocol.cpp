
#include "protocol.h"
#include "keymap.h"
#include <time.h>
#include <iostream>
#include <thread>


Protocol* Protocol::m_instance;



Protocol* Protocol::Instance()
{
	if(m_instance == nullptr)
	{
		m_instance = new Protocol();
	}

	return m_instance;
}

Protocol::Protocol()
{
    m_msgloopFlag = true;
    PRINT("lock\n");

#ifdef DEBUG_MSG
   
    m_msgthread = std::async(std::launch::async, &Protocol::msg_loop, this);
    m_keyloopFlag = true;
    m_keythread = std::async(std::launch::async, &Protocol::key_loop, this);
#else
    m_rcvMsgthread = std::async(std::launch::async, &Protocol::rcv_msg_loop, this);

    if (m_uartctl.setOpt(115200, 8, 'N', 1) == -1)
    {
        PRINT("Setup uart fail\n");
        return;
    }
#endif
}

Protocol::~Protocol()
{
#ifdef DEBUG_MSG
    m_msgloopFlag = false;
    m_msgthread.wait();
    m_keyloopFlag = false;
    m_keythread.wait();
#endif
}

#define CHECK_VAL(whatis, whatshouldbe) if (whatis != whatshouldbe) \
                                        { \
                                            PRINT("wrong data[%02x], should be[%02x]\n", whatis, whatshouldbe); \
                                            return INVALID_MSG; \
                                        }

int Protocol::rcv_msg_loop()
{
    static uint8_t rcv_buf[4096];
	int rcvLen = 0;
	PRINT("Start uart reading loop\n");
	while (m_msgloopFlag)
	{
		rcvLen = m_uartctl.UART_Recv(rcv_buf, sizeof(rcv_buf)/sizeof(rcv_buf[0]), 0xfffffff);
		PRINT("msg:");
		for (int i = 0; i < rcvLen; i++)
		{
			printf(" %02x", rcv_buf[i]);
		}
		printf("\n");
		int i = 0;
		while(i < rcvLen)
		{
			if (rcv_buf[i] == HH
				&& rcv_buf[i+1] == HE
				&& rcv_buf[i+4+rcv_buf[i+3]] == EH
				&& rcv_buf[i+5+rcv_buf[i+3]] == EE)
			{
				uint8_t* msg = new uint8_t[rcv_buf[i+3]+6];
				PRINT("new: %p\n", msg);
				memcpy(msg, rcv_buf+i, rcv_buf[i+3]+6);
				m_msgqueue.push_back(msg);
				i += rcv_buf[i+3]+6;
				m_cv.notify_all();
			}
			else
			{
				i++;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
    return 0;
}


int Protocol::ReceiveMsg(uint8_t* msg, int *size)
{
    uint8_t rcv_buf[LEN_GET_MSG+6];
    std::unique_lock<std::mutex> lck(m_mtx);
    if (m_msgqueue.size() == 0)
    {
        PRINT("lock\n");
        m_cv.wait(lck);
    }
    PRINT("[%lu] msgs remained in queue\n", m_msgqueue.size());

    if (m_msgqueue.size())
    {
        memcpy(rcv_buf, m_msgqueue.front(), LEN_GET_MSG+6);
        PRINT("delete: %p\n", m_msgqueue.front());
        delete[]m_msgqueue.front();
        m_msgqueue.pop_front();
    }
    lck.unlock();
    PRINT("unlock\n");
	PRINT("msg:");
	for (int i = 0; i < rcv_buf[3]+6; i++)
	{
		printf(" %02x", rcv_buf[i]);
	}
	printf("\n");

    CHECK_VAL(rcv_buf[0], HH);
    CHECK_VAL(rcv_buf[1], HE);
    int cmd = rcv_buf[2];
    int len = rcv_buf[3];
    CHECK_VAL(rcv_buf[4+len], EH);
    CHECK_VAL(rcv_buf[5+len], EE);

    memcpy(msg, rcv_buf+4, len);    
    *size = len;

    PRINT("Receive Message[%d]\n", cmd);
    return cmd;
}

void Protocol::SendMsg(int cmd, uint8_t* msg, int size)
{
    uint8_t snd_buf[32+6];
    snd_buf[0] = HH;
    snd_buf[1] = HE;
    snd_buf[2] = (uint8_t)cmd;
    snd_buf[3] = (uint8_t)size;
    for (int i = 0; i < size; i++)
    {
        snd_buf[4+i] = msg[i];
    }
    snd_buf[4+size] = EH;
    snd_buf[5+size] = EE;

	PRINT("msg:");

    for (int i = 0; i < 6+size; i++)
    {
        printf(" %02x", snd_buf[i]);
    }
    printf("\n");


#ifdef DEBUG_MSG
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
#else
    m_uartctl.UART_Send(snd_buf, 6+size);
#endif
}

#ifdef DEBUG_MSG

static uint8_t getRandomVal(int div)
{
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);

    uint8_t random = (uint8_t)((tv.tv_nsec&0x7ffffffff)/100%div);
    return random;
}

#include "topwindow.h"
int Protocol::msg_loop()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
	while (1)
	{
	    std::this_thread::sleep_for(std::chrono::seconds(1));
		if (TopWindow::GetInstance()->m_widget && TopWindow::GetInstance()->m_widget->IsTestStarted()) break;
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
    uint8_t* wrapmsg = new uint8_t[LEN_GET_MSG+6];
    PRINT("new: %p\n", wrapmsg);
    wrapmsg[0] = HH;
    wrapmsg[1] = HE;
    wrapmsg[2] = CMD_GET_SVN;
    wrapmsg[3] = LEN_GET_SVN;
    wrapmsg[4] = 1;
    for (int i = 1; i < wrapmsg[3]; i++)
    {
        wrapmsg[4+i] = getRandomVal(256)%2;
    }

    int msgsize = wrapmsg[3];
    wrapmsg[msgsize + 4] = EH;
    wrapmsg[msgsize + 5] = EE;
    m_msgqueue.push_back(wrapmsg);
    m_cv.notify_all();

	uint8_t code = 33;
	uint8_t sn = 1;
	uint8_t dip = 1;

	//		std::this_thread::sleep_for(std::chrono::seconds(1));
#define SET_MSG(snn, dipp) {\
		uint8_t* wrapmsg1 = new uint8_t[LEN_GET_MSG+6]; \
		wrapmsg1[0] = HH; \
		wrapmsg1[1] = HE; \
		wrapmsg1[2] = CMD_GET_DIS; \
		wrapmsg1[3] = 3; \
		int msgsize = wrapmsg1[3]; \
		wrapmsg1[4] = code; \
		wrapmsg1[5] = snn; \
		wrapmsg1[6] = dipp; \
		wrapmsg1[msgsize + 4] = EH; \
		wrapmsg1[msgsize + 5] = EE; \
		m_msgqueue.push_back(wrapmsg1); \
		m_cv.notify_all(); \
 	}

	SET_MSG(0xff, 0);
	SET_MSG(0xff, 0);
	SET_MSG(0xff, 0);
	SET_MSG(0xff, 0);
	SET_MSG(0xff, 0);
	SET_MSG(0xff, 0);
	SET_MSG(0xff, 0);

	SET_MSG(0, 7);
	while(1)
	{
		SET_MSG(sn, dip);
	    sn++;
	    if (sn == 60)
	    	break;
	    else if (sn == 55)
	        SET_MSG(0, 13);
    }
   
	SET_MSG(0, 8);
    PRINT("notify msg\n");

    return 0;
}

int Protocol::key_loop()
{
    char str[3];
    str[2] = '\0';
    while(m_keyloopFlag)
    {
		str[1] = '0';
        std::cin >> str;
		PRINT("str:%s\n", str);
        uint8_t* wrapmsg = new uint8_t[38];
		PRINT("new: %p\n", wrapmsg);
        wrapmsg[0] = HH;
        wrapmsg[1] = HE;
        wrapmsg[2] = CMD_GET_KEY;
        wrapmsg[3] = LEN_KEY;
        wrapmsg[4] = 0;
        wrapmsg[5] = 0;
        wrapmsg[6] = 0;
        wrapmsg[7] = EH;
        wrapmsg[8] = EE;

        switch (str[0])
        {
        case KEY_MODE_CHANGE:
            wrapmsg[4] = (uint8_t)atoi(str+1);
            break;
        case KEY_TAP_POSITION:
            wrapmsg[4] = (uint8_t)(atoi(str+1)<<4);
            PRINT("wrapmsg[4]: %d\n", (int)wrapmsg[4]);
            break;

        case KEY_SDQD:
            wrapmsg[5] = (uint8_t)(atoi(str+1)&0x1);
            PRINT("str+1[%s], wrapmsg[5]: %d\n", str+1, (int)wrapmsg[5]);
            break;
        case KEY_CKQD:
            wrapmsg[5] = (uint8_t)(atoi(str+1)<<1);
            PRINT("str+1[%s], wrapmsg[5]: %d\n", str+1, (int)wrapmsg[5]);
            break;
        case KEY_QDRC:
            wrapmsg[5] = (uint8_t)(atoi(str+1)<<2);
            PRINT("str+1[%s], wrapmsg[5]: %d\n", str+1, (int)wrapmsg[5]);
            break;

        case KEY_UP:
            wrapmsg[6] = 1;
            break;
        case KEY_DOWN:
            wrapmsg[6] = 2;
            break;
        case KEY_LEFT:
            wrapmsg[6] = 4;
            break;
        case KEY_RIGHT:
            wrapmsg[6] = 8;
            break;
        case KEY_PAGE_UP:
            wrapmsg[6] = 16;
            break;
        case KEY_PAGE_DOWN:
            wrapmsg[6] = 32;
            break;
        case KEY_ENTER:
            wrapmsg[6] = 64;
            break;
        case KEY_ESC:
            wrapmsg[6] = 128;
            break;

        default:
            break;
        }
        m_msgqueue.push_back(wrapmsg);
        m_cv.notify_all();
        PRINT("notify key\n");
    }

    return 0;
}
#endif
