watch_dog_base		  EQU      0x53000000;開門狗基址
GPIO_CONF			  EQU	   0X5600050
GPIO_DATA			  EQU	   0X5600054
		IMPORT xmain ;主程式
		
		;IMPORT  |Image$$SRAM$$Base| ;SRAM內存基址
				
		
			 PRESERVE8 ;SP 8字節對齊
         AREA RESET, CODE, READONLY
      
		 ENTRY
 
start
	     ldr sp,=4096
         bl disable_watchdog
		 bl io_init
		 bl led_on
		 bl _delay_
on_sdram

         ldr r0,=xmain
		 ;add r0,r0,#8
		 ;movs pc,r0
		 bl xmain
halt
         B halt
		 
disable_watchdog
		ldr r0,=watch_dog_base
		mov r1,#0
		str r1,[r0]
		movs pc,lr
io_init
	ldr r0,=GPIO_CONF
	mov r4,#3
	mov r2,#2
0
	add r4,#1       ;r4 ++
	lsl	r1,r2,r4  ;r1=r2<<r4
	orr r3,r1         ;r3=r3|r1
	cmp r4,#6
	bne  %B0
	str r3,[r0]
	movs pc,lr
led_on
	ldr r0,=GPIO_DATA
	mov r1,#3
0
	add r1,#1
	lsl r1,r1
	str r1,[r0]
	stmdb sp!,{r0-r1,lr}
	bl  _delay_
	ldmia sp!, {r0-r1,lr}
	cmp r1,#6
	bne %b0
	

_delay_ ;about 6 sec
	ldr r0,=0
	ldr r2,=0xFFFFFF
0
	add r0,#1
	cmp r0,r2
	bne %B0
	movs pc,lr

	END
