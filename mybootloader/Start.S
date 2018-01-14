#include "S3C2440.h"
#include "config.h"
.text
.global _start

_start:


/*----------關閉看門狗-----------*/
ldr r0 , =pWTCON
mov r1,#0
str r1,[r0]
/*-------------------------------*/

/*----------設置時鐘-------------*/
ldr	r0, =CLKDIVN
mov	r1, #3
str	r1, [r0]

/*
因為分頻配置為 FCLK:HCLK:PCLK = 1:2:4
因為HCLK非0 晶片手冊提到說 這種情況下要設置為異步bus

設置異步bus
*/
mrc p15,0,r1,c1,c0,0
orr r1,r1,#0xc0000000
mcr p15,0,r1,c1,c0,0

/*
    set MPLL_200M
	分頻配置完成後 即可設置頻率
	FCLK=200M HCLK=400M PCLK=800M
*/
	ldr r0,=MPLLLCON 
	ldr r1,=S3C2440_MPLL_200M
	str r1,[r0]
/*----------------------------------*/


/*----------配置存儲管理器使SDRAM可以使用-------------*/
	ldr r0,=BWSCON
	adr r1,sdram_config
	add r3,r0,#(13*4)
	
0:	
	ldr r2,[r1],#4
	str r2,[r0],#4
	cmp r0,r3
	bne 0b
/*------------------------------------------------------*/

/*--------------將代碼複製到代碼應該所在的鏈接地址上------------------*/
	ldr sp,=0x34000000
	bl     uart0_init
	/*
		為了得到代碼段長度，可以經過簡單的運算重鏈接腳本 ex : bss段起點 - _start(代碼段起始點)
		下面代碼就是要將原本0地址的代碼複製到_start鏈接腳本設定的地址，後面跳轉才可以跳轉到更大的RAM執行
	*/
	ldr r0,=0
	ldr r1,=_start
	ldr r2,=__bss_start
	sub r2,r2,r1
	bl	copy_code_to_SDRAM
	bl 	clean_bss
	
	
	
/*----------------------跳轉到main------------------------*/
	ldr lr,=halt
	ldr pc,=main	
halt:
	b	halt

sdram_config:
	.long 0x22011110	 //BWSCON
	.long 0x00000700	 //BANKCON0
	.long 0x00000700	 //BANKCON1
	.long 0x00000700	 //BANKCON2
	.long 0x00000700	 //BANKCON3  
	.long 0x00000700	 //BANKCON4
	.long 0x00000700	 //BANKCON5
	.long 0x00018005	 //BANKCON6
	.long 0x00018005	 //BANKCON7
	.long 0x008C04F4	 // REFRESH
	.long 0x000000B1	 //BANKSIZE
	.long 0x00000030	 //MRSRB6
	.long 0x00000030	 //MRSRB7


