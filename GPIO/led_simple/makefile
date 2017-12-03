all:
	arm-linux-gcc -g -o led.o -c led.S
	arm-linux-ld -Ttext 0x00000000 -g led.o -o led.elf
	arm-linux-objcopy -O binary -S led.elf led.bin
clean:
	rm -f led.elf led.bin


