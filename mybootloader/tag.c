#include "setup.h"
#include "params.h"

static struct tag *params;

void setup_start_tag(void)
{
	params = (struct tag *)params_addr;

	params->hdr.tag = ATAG_CORE;
	params->hdr.size = tag_size (tag_core);

	params->u.core.flags = 0;
	params->u.core.pagesize = 0;
	params->u.core.rootdev = 0;

	params = tag_next (params);
}

void setup_memory_tags(void)
{
	params->hdr.tag = ATAG_MEM;
	params->hdr.size = tag_size (tag_mem32);
	
	params->u.mem.start = 0x30000000;
	params->u.mem.size  = 64*1024*1024;
	
	params = tag_next (params);
}

void setup_commandline_tag(char *cmdline)
{
	int len=1,i=0;
	while(cmdline[i])
	{
		params->u.cmdline.cmdline[i]=cmdline[i];
		len++;
		i++;
	}
	
	params->hdr.tag  = ATAG_CMDLINE;
	params->hdr.size = (sizeof (struct tag_header) + len + 3) >> 2;
	
	

	params = tag_next (params);
}

void setup_end_tag(void)
{
	params->hdr.tag = ATAG_NONE;
	params->hdr.size = 0;
}


