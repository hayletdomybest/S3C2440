extern void nand_init(void);
extern void nand_wait(void);
extern void endeable_chip(int);
extern void nand_cmd(unsigned char);
extern void nand_addr(unsigned int);
extern unsigned char nand_data(void);
extern void nand_read(unsigned int ,unsigned char*,unsigned int);
