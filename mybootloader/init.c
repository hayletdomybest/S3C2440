#include "nand.h"
#include "serial.h"
int isNor()
{
	volatile unsigned int* adr=(volatile unsigned int*)0;
	int ref=0;
	int old_data=*adr; 
	*adr=0xFFFFFFFF;
	/*判斷nand or nor flash*/
	if(*adr==0xFFFFFFFF)
	{
		*adr=old_data;
		ref=0;
	}
	else
		ref=1;
	return ref;
}

/*複製程式碼到SDRAM*/
void  copy_code_to_SDRAM(unsigned char* src,unsigned char* dest,unsigned int size)
{
	if(isNor())
	{
		int i;
		for(i=0;i<size;i++)
			dest[i]=src[i];
	}
	else
	{
			nand_init();
			nand_read((unsigned int)src,dest,size);
	}
	
}
/*將bss段清為0 因為bss段是load一個初始化為0或者沒賦值的變數*/
void clean_bss(void)
{
	extern int __bss_start, __bss_end;
	int *p = &__bss_start;
	
	for (; p < &__bss_end; p++)
		*p = 0;
}
