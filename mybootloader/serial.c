#include "S3C2440.h"


#define TXD0READY   (1<<2)

#define PCLK            50000000    // init.c�е�clock_init��������PCLKΪ50MHz
#define UART_CLK        PCLK        //  UART0��ʱ��Դ��ΪPCLK
#define UART_BAUD_RATE  115200      // ������
#define UART_BRD        ((UART_CLK  / (UART_BAUD_RATE * 16)) - 1)

/*
 * ��l��UART0
 * 115200,8N1,?�y��
 */
void uart0_init(void)
{
    GPHCON  |= 0xa0;    // GPH2,GPH3�Χ@TXD0,RXD0
    GPHUP   = 0x0c;     // GPH2,GPH3?���W��

    ULCON0  = 0x03;     // 8N1(8??�u��A???�A1?�����)
    UCON0   = 0x05;     // �d?�覡�AUART??��?PCLK
    UFCON0  = 0x00;     // ���ϥ�FIFO
    UMCON0  = 0x00;     // ���ϥάy��
    UBRDIV0 = UART_BRD; // �i�S�v?115200
}

/*
 * ?�e�@?�r��
 */
void putc(unsigned char c)
{
    /* ���ݡA����?�e???����?�u�w?����?�e�X�h */
    while (!(UTRSTAT0 & TXD0READY));
    
    /* �VUTXH0�H�s����?�J?�u�AUART�Y��??��?�e�X�h */
    UTXH0 = c;
}

void putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		putc(str[i]);
		i++;
	}
}

