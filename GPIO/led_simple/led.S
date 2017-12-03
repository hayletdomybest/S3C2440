.equ _GPFCON_ ,0x56000050
.equ _GPFCON_val ,0x00005500
.equ _GPFDAT_ ,0x56000054
.equ delay_count , 0x00000002

.equ led_start_on , 0x7F
.text
	.global _start
	
_start:
	bl _led_init
	ldr r3,=led_start_on
l:
    adrl r5,led_val
	ldr  r0,[r5]
	bl _led_on
	add r5,r5,#4
	ldr  r0,[r5]
	bl _led_on
halt:
	b halt
	
	
	
_led_init:
	ldr r0,=_GPFCON_
	ldr r1,=_GPFCON_val
	str r1,[r0]
	mov pc,lr

_led_on:
	ldr r1,=_GPFDAT_
	str r0,[r1]
	mov pc,lr

_led_off:
	mov r0,#0xFF
	ldr r1,=_GPFDAT_
	str r0,[r1]
	mov pc,lr

	
led_val:
	.word 0x3F
	.word 0x5F
	.word 0x6F

