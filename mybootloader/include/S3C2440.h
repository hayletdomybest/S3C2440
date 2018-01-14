/*看門狗register base*/
#define pWTCON	 0x53000000
/*時鐘分頻register base*/ 
#define CLKDIVN	 0x4c000014

/*時鐘設置register base*/
#define MPLLLCON 0x4c000004  

/*存儲管理 register base*/
#define BWSCON	0x48000000


/*----------Nand flash相關----------*/
#define NFCONF (*((volatile unsigned long *)0x4E000000))
#define NFCONT (*((volatile unsigned long *)0x4E000004))
#define NFCMMD (*((volatile unsigned char *)0x4E000008))
#define NFADDR (*((volatile unsigned char *)0x4E00000C))
#define NFDATA (*((volatile unsigned char *)0x4E000010))
#define NFSTAT (*((volatile unsigned char *)0x4E000020))


/* GPIO registers */
#define GPACON              (*(volatile unsigned long *)0x56000000)
#define GPADAT              (*(volatile unsigned long *)0x56000004)

#define GPBCON              (*(volatile unsigned long *)0x56000010)
#define GPBDAT              (*(volatile unsigned long *)0x56000014)
#define GPBUP               (*(volatile unsigned long *)0x56000018)

#define GPCCON              (*(volatile unsigned long *)0x56000020)
#define GPCDAT              (*(volatile unsigned long *)0x56000024)
#define GPCUP               (*(volatile unsigned long *)0x56000028)

#define GPDCON              (*(volatile unsigned long *)0x56000030)
#define GPDDAT              (*(volatile unsigned long *)0x56000034)
#define GPDUP               (*(volatile unsigned long *)0x56000038)

#define GPECON    			(*(volatile unsigned long *)0x56000040)
#define GPEDAT    		    (*(volatile unsigned long *)0x56000044)
#define GPEUP     			(*(volatile unsigned long *)0x56000048)

#define GPFCON              (*(volatile unsigned long *)0x56000050)
#define GPFDAT              (*(volatile unsigned long *)0x56000054)
#define GPFUP               (*(volatile unsigned long *)0x56000058)

#define GPGCON              (*(volatile unsigned long *)0x56000060)
#define GPGDAT              (*(volatile unsigned long *)0x56000064)
#define GPGUP               (*(volatile unsigned long *)0x56000068)

#define GPHCON              (*(volatile unsigned long *)0x56000070)
#define GPHDAT              (*(volatile unsigned long *)0x56000074)
#define GPHUP               (*(volatile unsigned long *)0x56000078)


/*UART registers*/
#define ULCON0              (*(volatile unsigned long *)0x50000000)
#define UCON0               (*(volatile unsigned long *)0x50000004)
#define UFCON0              (*(volatile unsigned long *)0x50000008)
#define UMCON0              (*(volatile unsigned long *)0x5000000c)
#define UTRSTAT0            (*(volatile unsigned long *)0x50000010)
#define UTXH0               (*(volatile unsigned char *)0x50000020)
#define URXH0               (*(volatile unsigned char *)0x50000024)
#define UBRDIV0             (*(volatile unsigned long *)0x50000028)
 
 
