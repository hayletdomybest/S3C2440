#include "S3C2440.h"


#define TXD0READY   (1<<2)

#define PCLK            50000000    // init.c中的clock_init函数设置PCLK为50MHz
#define UART_CLK        PCLK        //  UART0的时钟源设为PCLK
#define UART_BAUD_RATE  115200      // 波特率
#define UART_BRD        ((UART_CLK  / (UART_BAUD_RATE * 16)) - 1)

/*
 * ﹍てUART0
 * 115200,8N1,?瑈北
 */
void uart0_init(void)
{
    GPHCON  |= 0xa0;    // GPH2,GPH3ノTXD0,RXD0
    GPHUP   = 0x0c;     // GPH2,GPH3?场┰

    ULCON0  = 0x03;     // 8N1(8??誹???1?氨ゎ)
    UCON0   = 0x05;     // 琩?よΑUART??方?PCLK
    UFCON0  = 0x00;     // ぃㄏノFIFO
    UMCON0  = 0x00;     // ぃㄏノ瑈北
    UBRDIV0 = UART_BRD; // 猧疭瞯?115200
}

/*
 * ?癳?才
 */
void putc(unsigned char c)
{
    /* 单?癳???い?誹?场?癳 */
    while (!(UTRSTAT0 & TXD0READY));
    
    /* UTXH0盚竟い??誹UART??ウ?癳 */
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

