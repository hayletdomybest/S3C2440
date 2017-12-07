watch_dog_base		  EQU      0x53000000					;watch_dog configure address
GPIO_CONF			  EQU	   0X56000050
GPIO_DATA			  EQU	   0X56000054
GPIO_VAL			      EQU     0x5500
		IMPORT xmain 							;Declare C main function is named xmain
		
				
		
			 PRESERVE8 						;SP(stack point) must allign 8 bytes					
         AREA RESET, CODE, READONLY
      
		 ENTRY
 
start
	     ldr sp,=4096
         bl disable_watchdog
		 bl io_init
0
		 bl led_on
		 b %b0
on_sdram

         ldr r0,=xmain
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
	ldr r1,=GPIO_VAL
	str r1,[r0]
	movs pc,lr
led_on
	ldr r0,=GPIO_DATA
	mov r2,#3
	mov r4,#0xFF
0
    mov r1,#1
	add r2,#1
	lsl r1,r1,r2
	sub r1,r4,r1
	str r1,[r0]
	stmdb sp!,{r0-r2,r4,lr}
	bl  _delay_
	ldmia sp!, {r0-r2,r4,lr}
	cmp r2,#6
	bne %b0
	movs pc,lr

_delay_ ;about 6 sec
	ldr r0,=0
	ldr r2,=600000
0
	add r0,#1
	cmp r0,r2
	bne %B0
	movs pc,lr

	END
