/******************************************************************************
*     $Date: 2005/02/17 20:26:25 $
*     $RCSfile: xtft_charcode.c,v $
*******************************************************************************

*******************************************************************************
*
*     XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
*     SOLELY FOR USE IN DEVELOPING PROGRAMS AND SOLUTIONS FOR
*     XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION
*     AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE, APPLICATION
*     OR STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS
*     IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
*     AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
*     FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
*     WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
*     IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
*     REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
*     INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*     FOR A PARTICULAR PURPOSE.
*     
*     (c) Copyright 2004 Xilinx, Inc.
*     All rights reserved.
*
******************************************************************************/
#include "xtft_charcode.h"

#define genPixels(a7, a6, a5, a4, a3, a2, a1, a0) (   ((a7) << 7)  | ((a6) << 6)  | ((a5) << 5)  | ((a4) << 4)  | ((a3) << 3)  | ((a2) << 2)  | ((a1) << 1) | ((a0)     ) )

Xuint8 XTft_vidChars[256][12] = 
	{ 
	/* ASCII 0x00 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d001 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d002 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d003 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d004 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d005 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d006 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d007 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d008 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d009 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d010 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d011 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d012 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d013 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d014 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d015 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x10 0d016 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x11 0d017 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x12 0d018 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x13 0d019 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x14 0d020 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x15 0d021 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x16 0d022 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x17 0d023 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x18 0d024 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x19 0d025 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x1a 0d026 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x1b 0d027 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x1c 0d028 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x1d 0d029 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x1e 0d030 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x1f 0d031 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x20 0d032 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x21 0d033 '!' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x22 0d034 '"' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x23 0d035 '#' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x24 0d036 '$' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x25 0d037 '%' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 0, 1, 0, 1, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 1, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x26 0d038 '&' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 1, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 1, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 1, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 1, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x27 0d039 ''' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x28 0d040 '(' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x29 0d041 ')' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x2a 0d042 '*' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 1, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 1, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x2b 0d043 '+' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x2c 0d044 ',' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x2d 0d045 '-' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x2e 0d046 '.' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x2f 0d047 '/' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x30 0d048 '0' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 1, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 1, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 1, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 1, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x31 0d049 '1' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 1, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x32 0d050 '2' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x33 0d051 '3' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x34 0d052 '4' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 1, 1, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 1, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x35 0d053 '5' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 1, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 1, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x36 0d054 '6' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 1, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x37 0d055 '7' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x38 0d056 '8' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x39 0d057 '9' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x3a 0d058 ':' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x3b 0d059 ';' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x3c 0d060 '<' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x3d 0d061 '=' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x3e 0d062 '>' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x3f 0d063 '?' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x40 0d064 '@' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 1, 0, 1, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 1, 0, 1, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 1, 1, 1, 1, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x41 0d065 'A' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x42 0d066 'B' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x43 0d067 'C' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x44 0d068 'D' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x45 0d069 'E' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x46 0d070 'F' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x47 0d071 'G' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x48 0d072 'H' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x49 0d073 'I' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x4a 0d074 'J' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x4b 0d075 'K' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 1, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x4c 0d076 'L' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x4d 0d077 'M' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 1, 0, 0, 0, 1, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 1, 0, 1, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x4e 0d078 'N' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 1, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 1, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 1, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 1, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 1, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 1, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x4f 0d079 'O' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x50 0d080 'P' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x51 0d081 'Q' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 1, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x52 0d082 'R' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x53 0d083 'S' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x54 0d084 'T' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x55 0d085 'U' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x56 0d086 'V' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x57 0d087 'W' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 1, 0, 1, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 1, 0, 0, 0, 1, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x58 0d088 'X' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x59 0d089 'Y' */ 
		{ 
		/* Line  0 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  1 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x5a 0d090 'Z' */ 
		{ 
		/* Line  0 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x5b 0d091 '[' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x5c 0d092 '\' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x5d 0d093 ']' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x5e 0d094 '^' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x5f 0d095 '_' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x60 0d096 '`' */ 
		{ 
		/* Line  0 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x61 0d097 'a' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 1, 1, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x62 0d098 'b' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x63 0d099 'c' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x64 0d100 'd' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 0, 1, 1, 1, 1, 1, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x65 0d101 'e' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 1, 1, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x66 0d102 'f' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 1, 0, 0, 1, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 1, 1, 1, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x67 0d103 'g' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 1, 1, 1, 1, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x68 0d104 'h' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x69 0d105 'i' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x6a 0d106 'j' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x6b 0d107 'k' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x6c 0d108 'l' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x6d 0d109 'm' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 1, 0, 1, 1, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x6e 0d110 'n' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x6f 0d111 'o' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x70 0d112 'p' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 1, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x71 0d113 'q' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x72 0d114 'r' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 1, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x73 0d115 's' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x74 0d116 't' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 1, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x75 0d117 'u' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 1, 1, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x76 0d118 'v' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x77 0d119 'w' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  6 */  genPixels( 1, 0, 0, 0, 0, 0, 1, 0),
		/* Line  7 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 0, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x78 0d120 'x' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 1, 0, 1, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 0, 0, 0, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x79 0d121 'y' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 1, 0, 0, 0, 0, 1, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 1, 1, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 1, 1, 0, 1, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  9 */  genPixels( 0, 0, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x7a 0d122 'z' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 1, 1, 1, 1, 1, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x7b 0d123 '{' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 1, 1, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x7c 0d124 '|' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x7d 0d125 '}' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 1, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 1, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x7e 0d126 '~' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 1, 0, 0, 1, 0, 0, 1, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 1, 1, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x7f 0d127 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x80 0d128 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x90 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0xa0 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0xb0 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0xc0 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0xd0 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0xe0 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0xf0 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x01 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x02 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x03 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x04 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x05 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x06 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x07 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x08 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x09 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0a 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0b 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0c 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0d 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0e 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		},
	/* ASCII 0x0f 0d000 ' ' */ 
		{ 
		/* Line  0 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  9 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 10 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line 11 */  genPixels( 0, 0, 0, 0, 0, 0, 0, 0)
		}
	};
