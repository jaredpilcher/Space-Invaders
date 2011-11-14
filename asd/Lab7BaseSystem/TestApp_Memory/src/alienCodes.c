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
#include "alienCodes.h"

#define genAlienPixels(a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0) ( ((a11) << 11) | ((a10) << 10) | ((a9) << 9) | ((a8) << 8) |  ((a7) << 7)  | ((a6) << 6)  | ((a5) << 5)  | ((a4) << 4)  | ((a3) << 3)  | ((a2) << 2)  | ((a1) << 1) | ((a0))  )

Xuint16 XTft_vidAliens[6][9] = 
	{ 
	    /* top-row alien, first guise*/ 
		{ 
   		/* Line  0 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  1 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  2 */  genAlienPixels( 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genAlienPixels( 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genAlienPixels( 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genAlienPixels( 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genAlienPixels( 1, 1, 1 ,0, 0, 0, 0, 0, 0, 0, 1, 0),
		},
	    /* top-row alien, second guise*/ 
		{ 
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0),
		/* Line  4 */  genAlienPixels( 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  5 */  genAlienPixels( 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0),
		/* Line  6 */  genAlienPixels( 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
	    /* */
		{ 
		/* Line  0 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  1 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  2 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  3 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  4 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  5 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  6 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  7 */  genAlienPixels( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
		/* Line  8 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		},
		{ 
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
	    /* */
		{ 
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
		{ 
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  4 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  6 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
	};