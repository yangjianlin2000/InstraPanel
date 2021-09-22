#ifndef _UART_CTL_H_
#define _UART_CTL_H_
#include <stdint.h>


class UartCtl
{
public:
    UartCtl();
    ~UartCtl();
    int setOpt(int nSpeed, int nBits, int nParity, int nStop);
    int UART_Recv(uint8_t *rcv_buf, int data_len, int timeout);
    int UART_Send(uint8_t *send_buf, int data_len);

private:
    int m_fdSerial;
};


#endif
