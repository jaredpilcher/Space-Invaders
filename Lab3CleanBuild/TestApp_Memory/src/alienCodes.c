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
#define genTankPixels(a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0) ( ((a14) << 14) | ((a13) << 13) | ((a12) << 12) | ((a11) << 11) | ((a10) << 10) | ((a9) << 9) | ((a8) << 8) |  ((a7) << 7)  | ((a6) << 6)  | ((a5) << 5)  | ((a4) << 4)  | ((a3) << 3)  | ((a2) << 2)  | ((a1) << 1) | ((a0))  )
#define genBunkerPixels(a5, a4, a3, a2, a1, a0) ( ((a5) << 5)  | ((a4) << 4)  | ((a3) << 3)  | ((a2) << 2)  | ((a1) << 1) | ((a0))  )
#define genBulletPixels(a2, a1, a0) (((a2) << 2)  | ((a1) << 1) | ((a0)) )
#define genShipPixels( a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0) ( ((a15) << 15) | ((a14) << 14) | ((a13) << 13) | ((a12) << 12) | ((a11) << 11) | ((a10) << 10) | ((a9) << 9) | ((a8) << 8) |  ((a7) << 7)  | ((a6) << 6)  | ((a5) << 5)  | ((a4) << 4)  | ((a3) << 3)  | ((a2) << 2)  | ((a1) << 1) | ((a0))  )
Xuint16 XTft_tank[9] = {
	genTankPixels(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	genTankPixels(0,0,0,0,0,0,0,1,0,0,0,0,0,0,0),
	genTankPixels(0,0,0,0,0,0,1,1,1,0,0,0,0,0,0),
	genTankPixels(0,0,0,0,0,0,1,1,1,0,0,0,0,0,0),
	genTankPixels(0,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	genTankPixels(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	genTankPixels(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	genTankPixels(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	genTankPixels(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
	};
	

Xuint16 XTft_bullets[8][5] = {
	{
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 1, 1),
		genBulletPixels(0, 1, 0),
	},
	{
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 1, 1),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
	},
	{
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 1, 1),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
	},
	{
		genBulletPixels(1, 0, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 0, 1),
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 0, 0),
	},
	{
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 0, 1),
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 0, 0),
		genBulletPixels(0, 1, 0),
	},
	{
		genBulletPixels(0, 0, 1),
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 0, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 0, 1),
	},
	{
		genBulletPixels(0, 1, 0),
		genBulletPixels(1, 0, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 0, 1),
		genBulletPixels(0, 1, 0),
	},
	{
		genBulletPixels(0, 0, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 1, 0),
		genBulletPixels(0, 0, 0),
	},
};

Xuint16 XTft_vidAliens[8][9] = 
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
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  4 */  genAlienPixels( 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0),
		/* Line  5 */  genAlienPixels( 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  6 */  genAlienPixels( 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
	    /* */
		{ 
		/* Line  1 */  genAlienPixels( 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1),
		/* Line  3 */  genAlienPixels( 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1),
		/* Line  4 */  genAlienPixels( 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1),
		/* Line  6 */  genAlienPixels( 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  6 */  genAlienPixels( 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0),
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
		{ 
		/* Line  1 */  genAlienPixels( 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  3 */  genAlienPixels( 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  4 */  genAlienPixels( 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0),
		/* Line  6 */  genAlienPixels( 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  6 */  genAlienPixels( 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  7 */  genAlienPixels( 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0),
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
		{ 
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  3 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  4 */  genAlienPixels( 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1),
		/* Line  3 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  6 */  genAlienPixels( 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0),
		/* Line  8 */  genAlienPixels( 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1),
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},
		{ 
		/* Line  1 */  genAlienPixels( 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0),
		/* Line  3 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  4 */  genAlienPixels( 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1),
		/* Line  3 */  genAlienPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  6 */  genAlienPixels( 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0),
		/* Line  7 */  genAlienPixels( 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0),
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		},		

	};
	
Xuint16 XTft_BunkerBlocks[5][5][6] = 
	{
		{
			/* zeroeth block*/ 
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 1, 1, 1),
			/* Line  1 */  genBunkerPixels( 0, 0, 1, 1, 1, 1),
			/* Line  2 */  genBunkerPixels( 0, 1, 1, 1, 1, 1),
			/* Line  3 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  5 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			},
			/* erode once */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 1, 1, 1),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 1, 1),
			/* Line  2 */  genBunkerPixels( 0, 1, 1, 1, 1, 1),
			/* Line  3 */  genBunkerPixels( 1, 0, 0, 1, 0, 1),
			/* Line  4 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  5 */  genBunkerPixels( 1, 0, 1, 0, 1, 1),
			},
			/* erode twice */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 1, 1, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 1, 1),
			/* Line  2 */  genBunkerPixels( 0, 1, 0, 1, 0, 1),
			/* Line  3 */  genBunkerPixels( 1, 0, 0, 1, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 1, 0, 1, 0, 1),
			/* Line  5 */  genBunkerPixels( 1, 0, 1, 0, 1, 0),
			},
			/* erode thrice */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 1, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 1, 0),
			/* Line  2 */  genBunkerPixels( 0, 1, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 0, 0, 1, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 1, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 1, 0, 0, 0, 1, 0),
			},
			/* erode four times */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
			
		},
		{
			/* first block*/  
			{ 
			/* Line  0 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  2 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  3 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  5 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			},
			/* erode once */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 1, 1, 0, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 0, 0, 1, 1, 0),
			/* Line  2 */  genBunkerPixels( 1, 1, 1, 1, 0, 1),
			/* Line  3 */  genBunkerPixels( 1, 0, 1, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 1, 1, 1, 0, 1, 1),
			/* Line  5 */  genBunkerPixels( 1, 1, 0, 1, 1, 1),
			},
			/* erode twice */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 1, 1, 0, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 0, 0, 1, 1, 0),
			/* Line  2 */  genBunkerPixels( 0, 1, 0, 1, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 0, 0, 1, 0, 1),
			/* Line  4 */  genBunkerPixels( 0, 1, 0, 0, 1, 0),
			/* Line  5 */  genBunkerPixels( 1, 1, 0, 1, 0, 1),
			},
			/* erode thrice */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 1, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 1, 0, 0, 1, 1, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 0, 0, 1, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 1, 0),
			/* Line  5 */  genBunkerPixels( 1, 0, 0, 1, 0, 0),
			},
			/* erode four times */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
		},
		{
			/* second block*/  
			{ 
			/* Line  0 */  genBunkerPixels( 1, 1, 1, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 0, 0),
			/* Line  2 */  genBunkerPixels( 1, 1, 1, 1, 1, 0),
			/* Line  3 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  5 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			},
			/* erode once */
			{ 
			/* Line  0 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 0, 0),
			/* Line  2 */  genBunkerPixels( 1, 0, 1, 1, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 1, 1, 1, 0, 1),
			/* Line  4 */  genBunkerPixels( 1, 1, 0, 1, 1, 1),
			/* Line  5 */  genBunkerPixels( 1, 0, 1, 1, 0, 1),
			},
			/* erode twice */
			{ 
			/* Line  0 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 1, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 0, 1, 0, 0, 1),
			/* Line  4 */  genBunkerPixels( 0, 1, 0, 1, 1, 0),
			/* Line  5 */  genBunkerPixels( 1, 0, 1, 1, 0, 1),
			},
			/* erode thrice */
			{ 
			/* Line  0 */  genBunkerPixels( 1, 0, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 1, 0, 0, 1, 0),
			/* Line  5 */  genBunkerPixels( 1, 0, 0, 0, 0, 0),
			},
			/* erode four times */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
		},
		{
		/* third block*/ 
			{ 
			/* Line  0 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  2 */  genBunkerPixels( 1, 1, 1, 1, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 1, 1, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 1, 1, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 1, 0, 0, 0, 0, 0),
			},
			/* erode once */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 1, 1, 0, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  2 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 1, 1, 1, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 1, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 1, 0, 0, 0, 0, 0),
			},
			/* erode twice */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 1, 1, 0, 0, 1),
			/* Line  1 */  genBunkerPixels( 0, 1, 0, 1, 0, 1),
			/* Line  2 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 1, 1, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 1, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
			/* erode thrice */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 1, 0, 0, 0, 1),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 0, 1),
			/* Line  2 */  genBunkerPixels( 1, 0, 1, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 1, 0, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
			/* erode four times */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
		},
		{
			/* fourth block*/ 
			{ 
			/* Line  0 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  2 */  genBunkerPixels( 0, 0, 1, 1, 1, 1),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 1, 1),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 1),
			},
			/* erode once */
			{ 
			/* Line  0 */  genBunkerPixels( 1, 0, 0, 1, 1, 1),
			/* Line  1 */  genBunkerPixels( 1, 1, 1, 1, 1, 1),
			/* Line  2 */  genBunkerPixels( 0, 0, 1, 1, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 1),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 1),
			},
			/* erode twice */
			{ 
			/* Line  0 */  genBunkerPixels( 1, 0, 0, 1, 0, 0),
			/* Line  1 */  genBunkerPixels( 1, 1, 0, 1, 0, 1),
			/* Line  2 */  genBunkerPixels( 0, 0, 1, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 1, 1, 1),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 1),
			},
			/* erode thrice */
			{ 
			/* Line  0 */  genBunkerPixels( 1, 0, 0, 1, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 1, 0, 0, 0, 1),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 1, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 1),
			},
			/* erode four times */
			{ 
			/* Line  0 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  1 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  2 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  3 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  4 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			/* Line  5 */  genBunkerPixels( 0, 0, 0, 0, 0, 0),
			},
		}
	};

		Xuint16 XTft_SpaceShip[8] = 
	    /* space ship*/ 
		{ 
   		/* Line  0 */  genShipPixels( 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0),
		/* Line  2 */  genShipPixels( 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0),
		/* Line  5 */  genShipPixels( 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0),
		/* Line  7 */  genShipPixels( 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0),
		/* Line  9 */  genShipPixels( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
		/* Line  12 */  genShipPixels( 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0),
		/* Line  14 */  genShipPixels( 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0),
		/* Line  15 */  genShipPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
		};
		
		Xuint16 XTft_Explosion[10] = 
	    /* explosion*/ 
		{ 
		/* Line  0 */  genAlienPixels( 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0),
		/* Line  1 */  genAlienPixels( 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0),
		/* Line  2 */  genAlienPixels( 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1),
		/* Line  3 */  genAlienPixels( 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0),
		/* Line  4 */  genAlienPixels( 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
		/* Line  5 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1),
		/* Line  6 */  genAlienPixels( 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
		/* Line  7 */  genAlienPixels( 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0),
		/* Line  8 */  genAlienPixels( 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0),
		};
		