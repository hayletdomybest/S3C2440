#include "S3C2440.h"
#include "serial.h"
#include "nand.h"
#include "tag.h"
#include "params.h"
#include "setup.h"


#define nand_kernel_addr 0x60000
#define kernel_addr 0x30007FC0
#define kernel_size 0x200000

#define MACH_TYPE_S3C2440   362
int main(void)
{
	void (*theKernel)(int, int, unsigned int);
	nand_read(nand_kernel_addr + 64,(unsigned char*)(kernel_addr + 64),kernel_size);

	
	putstr("set parameter\r\n");
	setup_start_tag();
	setup_memory_tags();
	setup_commandline_tag("noinitrd root=/dev/mtdblock3 init=/linuxrc console=ttySAC0");
	setup_end_tag();

	putstr("Start kernel.....\r\n");
	theKernel = (void (*)(int, int, unsigned int))(kernel_addr + 64);
	theKernel(0,MACH_TYPE_S3C2440,params_addr);
	
	putstr("error\r\n");
	while(1);
    return 0;	
}

