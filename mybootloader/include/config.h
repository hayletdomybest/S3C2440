#define S3C2440_MPLL_200M ((0x5c<<12)|(0x1<<4)|(0x02))

/* BWSCON */
#define DW8		 	(0x0)
#define DW16		 	(0x1)
#define DW32		 	(0x2)
#define WAIT		 	(0x1<<2)
#define UBLB		 	(0x1<<3)

#define B1_BWSCON	  	(DW16)
#define B2_BWSCON	  	(DW16)
//#define B3_BWSCON	  	(DW16 + WAIT + UBLB)
#define B3_BWSCON	  	(DW16 + UBLB)
#define B4_BWSCON	  	(DW16 + WAIT + UBLB)
#define B5_BWSCON	  	(DW8)
#define B6_BWSCON	  	(DW32)
#define B7_BWSCON	  	(DW32)

/* BANK0CON */
#define B0_Tacs		 	0x0	/*  0clk */
#define B0_Tcos		 	0x0	/*  0clk */
#define B0_Tacc		 	0x7	/* 14clk */
#define B0_Tcoh		 	0x0	/*  0clk */
#define B0_Tah		 	0x0	/*  0clk */
#define B0_Tacp		 	0x0
#define B0_PMC		 	0x0	/* normal */

/* BANK1CON */
#define B1_Tacs		 	0x0	/*  0clk */
#define B1_Tcos		 	0x0	/*  0clk */
#define B1_Tacc		 	0x7	/* 14clk */
#define B1_Tcoh		 	0x0	/*  0clk */
#define B1_Tah		 	0x0	/*  0clk */
#define B1_Tacp		 	0x0
#define B1_PMC		 	0x0

#define B2_Tacs		 	0x0
#define B2_Tcos		 	0x0
#define B2_Tacc		 	0x7
#define B2_Tcoh		 	0x0
#define B2_Tah		 	0x0
#define B2_Tacp		 	0x0
#define B2_PMC		 	0x0

#define B3_Tacs		 	0x0	/*  0clk */
#define B3_Tcos		 	0x3	/*  4clk */
#define B3_Tacc		 	0x7	/* 14clk */
#define B3_Tcoh		 	0x1	/*  1clk */
#define B3_Tah		 	0x0	/*  0clk */
#define B3_Tacp		 	0x3     /*  6clk */
#define B3_PMC		 	0x0	/* normal */

#define B4_Tacs		 	0x0	/*  0clk */
#define B4_Tcos		 	0x3	/*  4clk */
#define B4_Tacc		 	0x7	/* 14clk */
#define B4_Tcoh		 	0x1	/*  1clk */
#define B4_Tah		 	0x3	/*  4clk */
#define B4_Tacp		 	0x6 /*  6clk */
#define B4_PMC		 	0x0	/* normal */

#define B5_Tacs		 	0x0	/*  0clk */
#define B5_Tcos		 	0x0	/*  0clk */
#define B5_Tacc		 	0x7	/* 14clk */
#define B5_Tcoh		 	0x0	/*  0clk */
#define B5_Tah		 	0x0	/*  0clk */
#define B5_Tacp		 	0x0
#define B5_PMC		 	0x0	/* normal */

#define B6_MT		 	0x3	/* SDRAM */
#define B6_Trcd	 	 	0x1
#define B6_SCAN		 	0x1	/* 9bit */

#define B7_MT		 	0x3	/* SDRAM */
#define B7_Trcd		 	0x1	/* 3clk */
#define B7_SCAN		 	0x1	/* 9bit */

/* REFRESH parameter */
#define REFEN		 	0x1	/* Refresh enable */
#define TREFMD		 	0x0	/* CBR(CAS before RAS)/Auto refresh */
#define Trp		 	    0x0	/* 2clk */
#define Trc		    	0x3	/* 7clk */
#define Tchr		 	0x2	/* 3clk */
#define REFCNT		 	0x4f4	/* period=7.8125us, HCLK=100Mhz, (2048+1-7.8125*100) */
/**************************************/
