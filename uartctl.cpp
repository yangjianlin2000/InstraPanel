
#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include <sys/select.h>
#include "common.h"
#include "uartctl.h"


#define DEV_NAME    "/dev/ttymxc1"


UartCtl::UartCtl()
{
    m_fdSerial = open(DEV_NAME, O_RDWR | O_NOCTTY | O_NDELAY);
    if(m_fdSerial < 0)
    {
        perror(DEV_NAME);
        return;
    }
    // setting block， 0：block， FNDELAY：non-block
    if (fcntl(m_fdSerial, F_SETFL, 0) < 0)    //block
    {
        printf("fcntl failed!\n");
    }
    else
    {
        printf("fcntl=%d\n", fcntl(m_fdSerial, F_SETFL, 0));
    }
    if (isatty(m_fdSerial) == 0)
    {
        printf("standard input is not a terminal device\n");
        close(m_fdSerial);
    }
    else
    {
        printf("is a tty success!\n");
    }
    printf("fd-open=%d\n", m_fdSerial);
}

UartCtl::~UartCtl()
{
    if (m_fdSerial > 0)
    {
        close(m_fdSerial);
    }
}

int UartCtl::setOpt(int nSpeed, int nBits, int nParity, int nStop)
{
    struct termios newtio, oldtio;

    if (tcgetattr(m_fdSerial, &oldtio) != 0)
    {
        PRINT("SetupSerial\n");
        return -1;
    }

    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag |= CLOCAL | CREAD;

    newtio.c_cflag &= ~CSIZE;
    switch (nBits)
    {
        case 7:
            newtio.c_cflag |= CS7;
        break;
        case 8:
            newtio.c_cflag |= CS8;
        break;
        default:
            fprintf(stderr, "Unsupported data size\n");
            return -1;
    }

    switch (nParity)
    {
        case 'o':
        case 'O':
            newtio.c_cflag |= PARENB;
            newtio.c_cflag |= PARODD;
            newtio.c_iflag |= (INPCK | ISTRIP);
            break;
        case 'e':
        case 'E':
            newtio.c_iflag |= (INPCK | ISTRIP);
            newtio.c_cflag |= PARENB;
            newtio.c_cflag &= ~PARODD;
            break;
        case 'n':
        case 'N':
            newtio.c_cflag &= ~PARENB;
            break;
        default:
            fprintf(stderr, "Unsupported parity\n");
            return -1;
    }

    switch (nStop)
    {
        case 1:
            newtio.c_cflag &= ~CSTOPB;
        break;
        case 2:
            newtio.c_cflag |= CSTOPB;
        break;
        default:
            fprintf(stderr,"Unsupported stop bits\n");
            return -1;
    }

    switch (nSpeed)
    {
        case 2400:
            cfsetispeed(&newtio, B2400);
            cfsetospeed(&newtio, B2400);
            break;
        case 4800:
            cfsetispeed(&newtio, B4800);
            cfsetospeed(&newtio, B4800);
            break;
        case 9600:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        case 19200:
            cfsetispeed(&newtio, B19200);
            cfsetospeed(&newtio, B19200);
            break;
        case 38400:
            cfsetispeed(&newtio, B38400);
            cfsetospeed(&newtio, B38400);
            break;
        case 57600:
            cfsetispeed(&newtio, B57600);
            cfsetospeed(&newtio, B57600);
            break;
        case 115200:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
        case 230400:
            cfsetispeed(&newtio, B230400);
            cfsetospeed(&newtio, B230400);
            break;
        default:
            printf("\tSorry, Unsupported baud rate, set default 9600!\n\n");
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
    }

    newtio.c_cc[VTIME] = 1;
    newtio.c_cc[VMIN] = 1;

    tcflush(m_fdSerial,TCIFLUSH);
    if (tcsetattr(m_fdSerial, TCSANOW, &newtio) != 0)
    {
        perror("SetupSerial 3");
        return -1;
    }
    printf("Serial set done!\n");

    tcflush(m_fdSerial, TCIOFLUSH);//flush
    fcntl(m_fdSerial, F_SETFL, 0); //block

    return 0;
}

int UartCtl::UART_Recv(uint8_t *rcv_buf, int data_len, int timeout)
{
    int len, fs_sel;
    fd_set fs_read;
    struct timeval time;

    time.tv_sec = timeout / 1000;
    time.tv_usec = timeout % 1000 * 1000;

    FD_ZERO(&fs_read);
    FD_SET(m_fdSerial, &fs_read);

    fs_sel = select(m_fdSerial + 1, &fs_read, NULL, NULL, &time);
//    printf("fs_sel = %d\n", fs_sel);
    if(fs_sel)
    {
        len = read(m_fdSerial, rcv_buf, data_len);
        return len;
    }
    else
    {
//        printf("Sorry,I am wrong!");
        return -1;
    }
}

int UartCtl::UART_Send(uint8_t *send_buf, int data_len)
{
    ssize_t ret = 0;

    ret = write(m_fdSerial, send_buf, data_len);
    if (ret == data_len)
    {
        printf("send data is %s\n", send_buf);
        return ret;
    }
    else
    {
        printf("write device error\n");
        tcflush(m_fdSerial,TCOFLUSH);
        return -1;
    }
}

#if 0
int main (int argc, char *argv[])
{
	UartCtl uartctl;

    // setting opt
    if (uartctl.setOpt(115200, 8, 'N', 1)== -1)
    {
        fprintf(stderr, "Set opt Error\n");
        exit(1);
    }

    char rcv_buf[100];
    int len;

    while(1) 
    {
        len = uartctl.UART_Recv(rcv_buf, 256, 10000);
        if(len > 0)
        {
            rcv_buf[len] = '\0';
            printf("receive data is %s\n", rcv_buf);
            printf("len = %d\n", len);
            uartctl.UART_Send(rcv_buf, len);
        }
        else
        {
//          printf("cannot receive data\n");
        }
        usleep(100000);
    }
}
#endif
