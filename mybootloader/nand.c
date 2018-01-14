#include "S3C2440.h"
#include "serial.h"
void nand_init(void)
{
#define TACLS   0
#define TWRPH0  1
#define TWRPH1  0	

		/* 設置時序 */
        NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
        /* 使能NAND Flash控制器, 初始化ECC, 禁止片選, 設置時 */
        NFCONT = (1<<4)|(1<<1)|(1<<0);
}
void nand_wait(void)
{
	while(!(NFSTAT&1));
}

void endeable_chip(int flag)
{
	if(flag)
		NFCONT &=~(1<<1);
	else
		NFCONT |=(1<<1);
}
void nand_cmd(unsigned char cmd)
{
	int i;
	NFCMMD = cmd;
	for(i=0;i<10;i++);
}
void nand_addr(unsigned int addr)
{
	int i;
	int col=addr % 2048;//水平第幾個
	int rol=addr / 2048; //第幾頁

	/*第一個發送列地址低8位元*/
	NFADDR = col & 0xff;
	for(i=0;i<10;i++);

	/*第二個發送列地址高8位元*/
	NFADDR = (col>>8) & 0xff;
	for(i=0;i<10;i++);

	/*第三個發送行地址低8位元*/
	NFADDR = rol & 0xff;
	for(i=0;i<10;i++);

	/*第四個發送行地址中間8位元*/
	NFADDR = (rol>>8) & 0xff;
	for(i=0;i<10;i++);

	/*第五個發送行地址高8位元*/
	NFADDR = (rol>>16) & 0xff;
	for(i=0;i<10;i++);	

	
}
unsigned char nand_data(void)
{
	return NFDATA;
}
void nand_read(unsigned int addr,unsigned char* buf,unsigned int size)
{
	unsigned int col=addr % 2048;
	unsigned 	int i=0;
	/*使能晶片*/
	endeable_chip(1);
	while(i<size)
	{
		/*發出讀命令00h代表開始*/
		nand_cmd(0x00);
		
		/*發出5個訊號分別代表列列頁頁頁*/
		nand_addr(addr);
		/*發出讀命令30h代表結束*/
		nand_cmd(0x30);
		/*讀狀態，確定晶片已經完成讀訊號*/
		nand_wait();
		for(;(col<2048) && (i<size);col++)
		{
			buf[i]=nand_data();
			i++;
			addr++;
		}
		col=0;
		/*讀出資料*/
	}
	
	/*非使能晶片*/
	endeable_chip(0);
}


