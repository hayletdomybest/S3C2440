#include "S3C2440.h"
#include "serial.h"
void nand_init(void)
{
#define TACLS   0
#define TWRPH0  1
#define TWRPH1  0	

		/* �]�m�ɧ� */
        NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
        /* �ϯ�NAND Flash���, ��l��ECC, �T�����, �]�m�� */
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
	int col=addr % 2048;//�����ĴX��
	int rol=addr / 2048; //�ĴX��

	/*�Ĥ@�ӵo�e�C�a�}�C8�줸*/
	NFADDR = col & 0xff;
	for(i=0;i<10;i++);

	/*�ĤG�ӵo�e�C�a�}��8�줸*/
	NFADDR = (col>>8) & 0xff;
	for(i=0;i<10;i++);

	/*�ĤT�ӵo�e��a�}�C8�줸*/
	NFADDR = rol & 0xff;
	for(i=0;i<10;i++);

	/*�ĥ|�ӵo�e��a�}����8�줸*/
	NFADDR = (rol>>8) & 0xff;
	for(i=0;i<10;i++);

	/*�Ĥ��ӵo�e��a�}��8�줸*/
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
	/*�ϯഹ��*/
	endeable_chip(1);
	while(i<size)
	{
		/*�o�XŪ�R�O00h�N��}�l*/
		nand_cmd(0x00);
		
		/*�o�X5�ӰT�����O�N��C�C������*/
		nand_addr(addr);
		/*�o�XŪ�R�O30h�N����*/
		nand_cmd(0x30);
		/*Ū���A�A�T�w�����w�g����Ū�T��*/
		nand_wait();
		for(;(col<2048) && (i<size);col++)
		{
			buf[i]=nand_data();
			i++;
			addr++;
		}
		col=0;
		/*Ū�X���*/
	}
	
	/*�D�ϯഹ��*/
	endeable_chip(0);
}


