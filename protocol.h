#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <stdint.h>
#include <list>
#include <condition_variable>
#include <mutex>
#include <future>


#include "uartctl.h"
#include "common.h"

#define CMD_ASK_KEY 4 // length 0
#define CMD_GET_KEY 3 // length 3
#define CMD_GET_SVN 5 // length 8

#define CMD_CN_TEST 1 // length 1
#define CMD_CN_REST 2 // length 0

#define CMD_GET_DIS 6  // length 3~6
#define CMD_CN_DIS 7  // length 3


#define CMD_CN_FRA 10 // length 1
#define CMD_GET_MMU  // length 1
#define CMD_GET_EMSG 7 // length 8
#define CMD_CN_EMSG 6 // length 8
#define CMD_GET_CMSG 13 // length 8
#define CMD_CN_CMSG 14 // length 8


#define HH	0xAA
#define HE	0x55

#define EH	0x50
#define EE	0xA0


#define INVALID_MSG 0xffffffff

#define LEN_KEY 3
#define LEN_GET_MSG 32
#define LEN_GET_SVN 8
#define LEN_CN_MSG 3


#define DEBUG_MSG

class Protocol
{
public:
	static Protocol* Instance();

	int ReceiveMsg(uint8_t* msg, int *size);
    void SendMsg(int cmd, uint8_t* msg, int size);

private:
    Protocol();
    ~Protocol();
	int rcv_msg_loop();

#ifdef DEBUG_MSG
	int msg_loop();
	int key_loop();
#endif
private:
#ifdef DEBUG_MSG
	bool m_keyloopFlag;
	std::future<int> m_msgthread;
	std::future<int> m_keythread;
#endif
    bool m_msgloopFlag;
    std::list<uint8_t*> m_msgqueue;
	std::future<int> m_rcvMsgthread;
	std::mutex m_mtx;
	std::condition_variable m_cv;
	UartCtl m_uartctl;
	static Protocol* m_instance;
};

#endif


