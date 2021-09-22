#include <string.h>
#include <unistd.h>

#include "topwindow.h"
#include "instrpanel_ybb.h"
#include "instrpanel_jsc.h"
#include "instrpanel_zdc.h"
#include "instrpanel_dlc_a.h"
#include "instrpanel_jsc_d.h"
#include "instrpanel_zdc_d.h"
#include "instrpanel_dlc_d.h"
#include "instrpanel_jsc_c.h"
#include "instrpanel_ybb_b.h"
#include "instrpanel_dlc_b.h"
#include "instrpanel_jsc_b.h"
#include "keymap.h"
#include "protocol.h"
#include "panelveri0.h"
#include "panelveri1.h"
#include "panelveri2.h"
#include "panelveri3.h"


//! For key monitor
static uint16_t modeval_s = 0;
static uint16_t gsetval_s = 0;
static uint16_t sdqd_s = 0;
static uint16_t ckqd_s = 0;
static uint16_t qdrc_s = 0;


//! t10
PanelBase* create_YBB_A(QWidget* parent)
{
    InstrPanel_YBB* current_wgt = new InstrPanel_YBB(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_DLC_A(QWidget* parent)
{
    InstrPanel_DLC_A* current_wgt = new InstrPanel_DLC_A(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_JSC_A(QWidget* parent)
{
    InstrPanel_JSC* current_wgt = new InstrPanel_JSC(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_ZDC_A(QWidget* parent)
{
    InstrPanel_ZDC* current_wgt = new InstrPanel_ZDC(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

//! 122
PanelBase* create_YBB_B(QWidget* parent)
{
    InstrPanel_YBB_B* current_wgt = new InstrPanel_YBB_B(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_DLC_B(QWidget* parent)
{
    InstrPanel_DLC_B* current_wgt = new InstrPanel_DLC_B(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_JSC_B(QWidget* parent)
{
    InstrPanel_JSC_B* current_wgt = new InstrPanel_JSC_B(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_JSC_C(QWidget* parent)
{
    InstrPanel_JSC_C* current_wgt = new InstrPanel_JSC_C(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

//! t10c
PanelBase* create_DLC_D(QWidget* parent)
{
    InstrPanel_DLC_D* current_wgt = new InstrPanel_DLC_D(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_JSC_D(QWidget* parent)
{
    InstrPanel_JSC_D* current_wgt = new InstrPanel_JSC_D(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_ZDC_D(QWidget* parent)
{
    InstrPanel_ZDC_D* current_wgt = new InstrPanel_ZDC_D(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

//! verimode
PanelBase* create_veri0(QWidget* parent)
{
    PRINT("create veri0\n");
    PanelVeri0* current_wgt = new PanelVeri0(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_veri1(QWidget* parent)
{
    PRINT("create veri1\n");
    PanelVeri1* current_wgt = new PanelVeri1(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_veri2(QWidget* parent)
{
    PRINT("create veri2\n");
    PanelVeri2* current_wgt = new PanelVeri2(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

PanelBase* create_veri3(QWidget* parent)
{
    PRINT("create veri3\n");
    PanelVeri3* current_wgt = new PanelVeri3(parent);
    return dynamic_cast<PanelBase*>(current_wgt);
}

create_func* group_veri[] =
{
    create_veri0,
    create_veri1,
    create_veri2,
    create_veri3,
};

create_func* group_t10[] =
{
    nullptr,
    create_YBB_A,
    create_DLC_A,
    create_JSC_A,
    create_ZDC_A
};

create_func* group_t10c[] =
{
    nullptr,
    create_YBB_A,
    create_DLC_D,
    create_JSC_D,
    create_ZDC_D
};

create_func* group_122[] =
{
    nullptr,
    create_YBB_B,
    create_DLC_B,
    create_JSC_B,
    create_JSC_C
};

TopWindow* TopWindow::m_instance;

TopWindow* TopWindow::GetInstance()
{
	return m_instance;
}

TopWindow::TopWindow(QWidget *parent) : QWidget(parent)
{
	m_warningDiag = nullptr;
	m_timer = nullptr;
	m_proto = Protocol::Instance();
	
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("TopWindow"));
    resize(800, 480);

    m_loop_flag = true;
//    checkProductType();
//    connect(this, SIGNAL(sig_getKey(unsigned int)), this, SLOT(slot_getKey(unsigned int)), Qt::QueuedConnection);
    connect(this, SIGNAL(sig_getMsg(unsigned int, unsigned char*, int)), this, SLOT(slot_getMsg(unsigned int, unsigned char*, int)), Qt::QueuedConnection);

	//! Get Initial key value
	//getInitialKey();
    m_modeIndex = getModeIndex();
    m_shiftIndex = getShiftIndex();
    if (m_modeIndex == 0)
    {
        setVeriMode();
        m_widget_index = m_shiftIndex;
    }
    else
    {
        checkProductType();
        m_widget_index = m_modeIndex;
    }
    m_key_loop_thread = std::async(std::launch::async, &TopWindow::msgLoop, this);

    m_widget = m_createfunc[m_widget_index](this);
	m_widget->SetFuncCode(m_modecode[m_widget_index]);
	if (m_modeIndex == 0)
	{
	    //! if current mode is verification mode, directly start test
        //m_widget->DoTest(true);
    }
    m_widget->show();

    m_instance = this;
}

TopWindow::~TopWindow()
{
    m_loop_flag = false;
    m_key_loop_thread.wait();
}

#define VERI_MODE_FLAG_FILE "/opt/veri_flag"

void TopWindow::setVeriMode()
{
	static uint8_t veri[5] = {0, 2, 3, 4, 0};

    // initialize create function list
    m_createfunc.clear();
    m_modecode.clear();
    PRINT("set mode code queue: ");
    for(int i = 0; i < sizeof(group_veri)/sizeof(group_veri[0]); i++)
    {
        m_modecode.push_back(veri[i]);
        m_createfunc.push_back(group_veri[i]);
        printf("%d ", m_modecode[i]);
    }
    printf("\n");
}

bool TopWindow::isVeriMode()
{
    return m_modeIndex == 0 ? true : false;
}

void TopWindow::getInitialKey()
{
	uint8_t sendBuf[1];
	int sendSize = 1;

	sendBuf[0] = 3;
	m_proto->SendMsg(CMD_ASK_KEY, sendBuf, 0);

	uint8_t recvBuf[32];
	int recvSize = 0;
	while(CMD_GET_KEY != m_proto->ReceiveMsg(recvBuf, &recvSize))
	{
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

    struct bs_msg{
        unsigned msel: 4;
        unsigned gset: 4;
        unsigned sdqd: 1;
        unsigned ckqd: 1;
        unsigned qdrc: 1;
        unsigned reserved1: 5;
        unsigned up: 1;
        unsigned dn: 1;
        unsigned lf: 1;
        unsigned rt: 1;
        unsigned pgup: 1;
        unsigned pgdn: 1;
        unsigned ent: 1;
        unsigned esc: 1;
        unsigned reserved2: 8;
    }key;

    memcpy(&key, recvBuf, LEN_KEY);
	modeval_s = (uint16_t)key.msel;
	gsetval_s = (uint16_t)key.gset;
	sdqd_s = (uint16_t)key.sdqd;
	ckqd_s = (uint16_t)key.ckqd;
	qdrc_s = (uint16_t)key.qdrc;
}

int TopWindow::getModeIndex()
{
#if 1
	return 4;
#endif
	PRINT("get mode: %d\n", (int)modeval_s);
	return (int)modeval_s;
}

int TopWindow::getShiftIndex()
{
#if 1
		return 3;
#endif
	PRINT("get gear: %d\n", (int)gsetval_s);
	return (int)gsetval_s;
}

void TopWindow::checkProductType()
{
	static uint8_t t10[5] = {0, 11, 12, 13, 14};
	static uint8_t t10c[5] = {0, 11, 32, 33, 34};
	static uint8_t m122[5] = {0, 21, 22, 23, 24};
    // initialize create function list

    m_createfunc.clear();
    m_modecode.clear();
    PRINT("set mode code queue: ");
    for(int i = 0; i < 5; i++)
    {
        if (0 == access("./t10c_flag", F_OK))
        {
    	    m_modecode.push_back(t10c[i]);
            m_createfunc.push_back(group_t10c[i]);
        }
        else if (0 == access("./m122_flag", F_OK))
        {
    	    m_modecode.push_back(m122[i]);
            m_createfunc.push_back(group_122[i]);
        }
        else
        {
    	    m_modecode.push_back(t10[i]);
            m_createfunc.push_back(group_t10[i]);
        }
        printf("%d ", m_modecode[i]);
    }
    printf("\n");
}

union KeyEvent TopWindow::parseKey(uint8_t *msg)
{
    struct bs_msg{
        unsigned msel: 4;
        unsigned gset: 4;
        unsigned sdqd: 1;
        unsigned ckqd: 1;
        unsigned qdrc: 1;
        unsigned reserved1: 5;
        unsigned up: 1;
        unsigned dn: 1;
        unsigned lf: 1;
        unsigned rt: 1;
        unsigned pgup: 1;
        unsigned pgdn: 1;
        unsigned ent: 1;
        unsigned esc: 1;
        unsigned reserved2: 8;
    }key;

    memcpy(&key, msg, LEN_KEY);

    union KeyEvent keyevent;
    if (key.up)
    {
        keyevent.keyinfo.keyid = KEY_UP;
        keyevent.keyinfo.data = 1;
    }
    else if (key.dn)
    {
        keyevent.keyinfo.keyid = KEY_DOWN;
        keyevent.keyinfo.data = 1;
    }
    else if (key.lf)
    {
        keyevent.keyinfo.keyid = KEY_LEFT;
        keyevent.keyinfo.data = 1;
    }
    else if (key.rt)
    {
        keyevent.keyinfo.keyid = KEY_RIGHT;
        keyevent.keyinfo.data = 1;
    }
    else if (key.pgup)
    {
        keyevent.keyinfo.keyid = KEY_PAGE_UP;
        keyevent.keyinfo.data = 1;
    }
    else if (key.pgdn)
    {
        keyevent.keyinfo.keyid = KEY_PAGE_DOWN;
        keyevent.keyinfo.data = 1;
    }
    else if (key.ent)
    {
        keyevent.keyinfo.keyid = KEY_ENTER;
        keyevent.keyinfo.data = 1;
    }
    else if (key.esc)
    {
        keyevent.keyinfo.keyid = KEY_ESC;
        keyevent.keyinfo.data = 1;
    }
    else if (modeval_s != (uint16_t)key.msel)
    {
        keyevent.keyinfo.keyid = KEY_MODE_CHANGE;
        keyevent.keyinfo.data = key.msel;
        modeval_s = key.msel;
    	PRINT("Mode changed: %d\n", (int)modeval_s);
    }
    else if (gsetval_s != (uint16_t)key.gset)
    {
        keyevent.keyinfo.keyid = KEY_TAP_POSITION;
        keyevent.keyinfo.data = key.gset;
		gsetval_s = key.gset;
    	PRINT("Gear changed: %d\n", (int)gsetval_s);
    }
    else if (sdqd_s != (uint16_t)key.sdqd)
    {
        keyevent.keyinfo.keyid = KEY_SDQD;
        keyevent.keyinfo.data = key.sdqd;
        sdqd_s = key.sdqd;
    }
    else if (ckqd_s != key.ckqd)
    {
        keyevent.keyinfo.keyid = KEY_CKQD;
        keyevent.keyinfo.data = key.ckqd;
        ckqd_s = key.ckqd;
    }
    else if (qdrc_s != key.qdrc)
    {
        keyevent.keyinfo.keyid = KEY_QDRC;
        keyevent.keyinfo.data = key.qdrc;
        qdrc_s = key.qdrc;
    }
    return keyevent;
}

void TopWindow::getKey(unsigned int key)
{
    KeyEvent keyevent;
    keyevent.keyval = key;
    PRINT("Get Key[%d]\n", (int)keyevent.keyinfo.keyid);

	if (m_widget && m_widget->IsAutoTestState())
	{
		if (keyevent.keyinfo.keyid == KEY_ESC)
		{
			m_widget->DoTest(false);
		}
		else
		{
			setWarning("自 动 测 试 中 !");
		}
		return;
	}

	if(m_modeIndex != 0 && keyevent.keyinfo.keyid == KEY_MODE_CHANGE)
	{
		if(keyevent.keyinfo.data == 0)
		{
			ERROR("Do not support change to Verify mode\n");
			return;
		}

        //! check if working is started
        if (m_widget->IsTestStarted())
        {
            PRINT("Test is on-going, mode can't be changed!!!\n");
			setWarning("正 在 测 试 中 !");
        }
        else
        {
            delete m_widget;
            m_widget = NULL;
            m_widget_index = keyevent.keyinfo.data;
            m_widget = m_createfunc[m_widget_index](this);
			m_widget->SetFuncCode(m_modecode[m_widget_index]);
            m_widget->show();
        }
    }
    else
    {
        m_widget->keyEvent(keyevent.keyinfo);
    }
}

void TopWindow::slot_shiftKeyChange(unsigned int val)
{
    if (val == m_widget_index)
    {
        PRINT("Shift key value[%d] was't changed\n", val); 
        return;
    }
    else if (val >=  m_createfunc.size())
    {
        PRINT("Invalid shift key[%d]\n", val);
        return;
    }
    
    m_widget->DoTest(false);
    m_widget->hide();
    m_widget->deleteLater();

    m_widget_index = val;
    PRINT("Enter No.[%u] UI\n", val);
    m_widget = m_createfunc[m_widget_index](this);
    m_widget->SetFuncCode(m_modecode[m_widget_index]);
    m_widget->show();

    //m_widget->DoTest(true);
}


#include <iostream>
#include <time.h>

int getRandomVal(int div)
{
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);

    int random = (int)(tv.tv_nsec&0x7ffffffff)/100%div;
    return random;
}



#define MSG_TYPE(msg) MSG_TYPE_KEY

void TopWindow::msgLoop()
{
    uint8_t msg[64];
    int size;
    while(m_loop_flag)
    {
        uint32_t cmd = m_proto->ReceiveMsg(msg, &size);
		uint8_t* sendMsg = new unsigned char[size];
		PRINT("new: %p\n", sendMsg);
		memcpy(sendMsg, msg, size);
		emit sig_getMsg(cmd, sendMsg, size);

#if 0
        if (cmd == CMD_GET_KEY)
        {
            assert(size == LEN_KEY);
            PRINT("emit key msg[%x %x %x]\n", msg[0], msg[1], msg[2]);
            emit sig_getKey(parseKey(msg).keyval);
        }
        else if (cmd == CMD_GET_SVN)
        {
        	//! svn message length is fixed
            assert(size == LEN_GET_SVN);
			m_widget->RecvSVN(msg, size);
            PRINT("Receive msg[");
            for (int i = 0; i < size; i++)
            {
				printf("%02x ", msg[i]);
            }
            printf("]\n");
        }
        else if (cmd == CMD_GET_CMSG)
        {
        	//! can message length is not fixed
            //assert(size == LEN_GET_MSG);
            m_widget->RecvCanValue(msg, size);
            PRINT("Receive msg[");
            for (int i = 0; i < size; i++)
            {
				printf("%02x ", msg[i]);
            }
            printf("]\n");
        }
        else if (cmd == CMD_GET_EMSG)
        {
        	//! io message length is not fixed
            //assert(size == LEN_GET_MSG);
            m_widget->RecvIoValue(msg, size);
            PRINT("Receive msg[");
            for (int i = 0; i < size; i++)
            {
				printf("%02x ", msg[i]);
            }
            printf("]\n");
        }
#endif
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}


void TopWindow::slot_getMsg(unsigned int cmd, unsigned char* msg, int size)
{
	std::unique_lock<std::mutex> lck(m_mtx);
	PRINT("Receive msg[%d] :", cmd);
	for (int i = 0; i < size; i++)
	{
		printf("%02x ", msg[i]);
	}
	printf("\n");

	if (cmd == CMD_GET_KEY)
	{
		assert(size == LEN_KEY);
		PRINT("emit key msg[%x %x %x]\n", msg[0], msg[1], msg[2]);
		getKey(parseKey(msg).keyval);
	}
	else if (cmd == CMD_GET_SVN)
	{
		//! svn message length is fixed
		assert(size == LEN_GET_SVN);
		m_widget->RecvSVN(msg);
	}
	else if (cmd == CMD_GET_DIS)
	{
		//! dis message length is 3~6
		m_widget->RecvMsg(msg, size);
	}
#if 0
	else if (cmd == CMD_GET_CMSG)
	{
		//! can message length is not fixed
		//assert(size == LEN_GET_MSG);
		m_widget->RecvCanValue(msg, size);
		PRINT("Receive msg[");
		for (int i = 0; i < size; i++)
		{
			printf("%02x ", msg[i]);
		}
		printf("]\n");
	}
	else if (cmd == CMD_GET_EMSG)
	{
		//! io message length is not fixed
		//assert(size == LEN_GET_MSG);
		m_widget->RecvIoValue(msg, size);
		PRINT("Receive msg[");
		for (int i = 0; i < size; i++)
		{
			printf("%02x ", msg[i]);
		}
		printf("]\n");
	}
#endif

	PRINT("delete: %p\n", msg);
	delete[]msg;
	msg = nullptr;
	PRINT("delete: %p\n", msg);
}


void TopWindow::slot_sendCanValue(unsigned char* msg, int size)
{
    if (msg)
    {

        delete[]msg;
    }
}

void TopWindow::slot_sendIoValue(unsigned char* msg, int size)
{
    if (msg)
    {

        delete[]msg;
    }
}

void TopWindow::slot_warningTimeOut()
{
	PRINT("Warning diaglogue is to be deleted\n");
	m_timer->deleteLater();
	m_timer = nullptr;
	m_warningDiag->deleteLater();
	m_warningDiag = nullptr;
}

void TopWindow::setWarning(const char* text)
{
	//! if warning dialogue is on, do not create new diagolue
	PRINT("%s\n", text);
	if (m_warningDiag)
	{
		ERROR("Warning diaglogue is showing\n");
		return;
	}
	PRINT("Show warning diaglogue\n");

#define WARNING_RECT_STYLE "border-radius: 8px; background-color:rgba(20,60,120,240); color:rgb(255,255,255);font:bold 48px;"
    const int interval = 1000;
    m_warningDiag = new QLabel(this);
	m_warningDiag->setStyleSheet(WARNING_RECT_STYLE);
	m_warningDiag->setGeometry(200, 120, 400, 240);
	m_warningDiag->setText(text);
	m_warningDiag->setAlignment(Qt::AlignCenter);
	m_warningDiag->show();
    m_timer = new QTimer(this);
	m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slot_warningTimeOut()));
	m_timer->start(interval);
}

