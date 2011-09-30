/******************************************************************************
*     $Date: 2005/02/17 20:26:25 $
*     $RCSfile: xtft_l.c,v $
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
/***************************** Include Files ********************************/

#include "xtft_l.h"
#include "alienCodes.h"
#include "text.h"

#define FRAME3 0x00400000

/************************** Constant Definitions ****************************/



void XTft_FillScreen2(Xuint32 BaseAddress, Xuint32 xu, Xuint32 yu, Xuint32 xl, 
                Xuint32 yl, Xuint32 col)
{
    Xuint32 x;
    Xuint32 y;

    for(x = xu; x <= xl; x++)
    {
        for(y = yu; y <= yl; y++)
        {
            XTft_mSetPixel(BaseAddress, x, y, col);
        }
    }
}



void XTft_EraseAlien(
  Xuint32 BaseAddress,
  Xuint32 BGAddress,
  Xuint32 type,
  Xuint32 xu,
  Xuint32 yu)
 {  
  Xuint32 col, x, y;
  Xuint16 val;
  for (y = 0; y < XTFT_ALIEN_HEIGHT; y++)
  {
    val = XTft_vidAliens[(Xuint32) type][y/2];
    for (x = 0; x < XTFT_ALIEN_WIDTH; x++)
    {
		if (yu+y > 330 || yu+y < 100)
			col = XTft_mGetPixel(BGAddress, xu+x, yu+y);
		else
			col = 0;
     XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
    }
  }
}


void XTft_DrawAlien(
  Xuint32 BaseAddress,
  Xint16 ch,
  Xuint32 xu,
  Xuint32 yu,
  Xuint32 fgColor)
{
  Xuint32 col, x, y;
  Xuint16 val;
  for (y = 0; y < XTFT_ALIEN_HEIGHT; y++)
  {
    val = XTft_vidAliens[(Xuint32) ch][y/2];
    for (x = 0; x < XTFT_ALIEN_WIDTH; x++)
    {
      if (val & (1 << (XTFT_ALIEN_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
	    continue;
      XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
    }
  }
}


void XTft_DrawTank(
  Xuint32 BaseAddress,
  Xuint32 xu,
  Xuint32 yu,
  Xuint32 fgColor,
  Xuint32 bgColor)
{
  Xuint32 col, x, y;
  Xuint16 val;

  for (y = 0; y < XTFT_TANK_HEIGHT; y++)
  {
    val = XTft_tank[y/2];
    for (x = 0; x < XTFT_TANK_WIDTH; x++)
    {
      if (val & (1 << (XTFT_TANK_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
		continue;
        //col = bgColor;
      
      XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
    }
  }
}

void XTft_DrawBunkerBlock(
  Xuint32 BaseAddress,
  Xuint32 type,
  Xuint32 erosion,
  Xuint32 xu,
  Xuint32 yu,
  Xuint32 fgColor,
  Xuint32 bgColor)
{
  Xuint32 col, x, y;
  Xuint16 val;

  for (y = 0; y < XTFT_BUNKER_BLOCK_HEIGHT; y++)
  {
    val = XTft_BunkerBlocks[type][erosion][y/2];
    for (x = 0; x < XTFT_BUNKER_BLOCK_WIDTH; x++)
    {
      if (val & (1 << (XTFT_BUNKER_BLOCK_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
		col = bgColor;
        //col = bgColor;
      
      XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
	  XTft_mSetPixel(FRAME3, xu+x, yu+y, col);
    }
  }
}

void XTft_EraseBullet(
  Xuint32 BaseAddress,
  Xuint32 BGAddress,
  Xuint32 type,
  Xuint32 xu,
  Xuint32 yu)
 {  
  Xuint32 col, x, y;
  Xuint16 val;

  for (y = 0; y < XTFT_BULLET_HEIGHT; y++)
  {
    val = XTft_bullets[(Xuint32) type][y/2];
    for (x = 0; x < XTFT_BULLET_WIDTH; x++)
    {
      if (val & (1 << (XTFT_BULLET_WIDTH/2 - x/2 - 1)))
        col = XTft_mGetPixel(BGAddress, xu+x, yu+y);
      else
		continue;
        //col = bgColor;
      
        XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
     }
  }
}
 
void XTft_DrawBullet(
  Xuint32 BaseAddress,
  Xuint32 type,
  Xuint32 xu,
  Xuint32 yu,
  Xuint32 fgColor,
  Xuint32 bgColor)
{
  Xuint32 col, x, y;
  Xuint16 val;

  for (y = 0; y < XTFT_BULLET_HEIGHT; y++)
  {
    val = XTft_bullets[(Xuint32) type][y/2];
    for (x = 0; x < XTFT_BULLET_WIDTH; x++)
    {
      if (val & (1 << (XTFT_BULLET_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
		continue;
        //col = bgColor;
      
        XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
     }
  }
}

void XTft_DrawShip(
  Xuint32 BaseAddress,
  Xuint32 xu,
  Xuint32 yu,
  Xuint32 fgColor,
  Xuint32 bgColor)
{
  Xuint32 col, x, y;
  Xuint32 val;

  for (y = 0; y < XTFT_SHIP_HEIGHT; y++)
  {
    val = XTft_SpaceShip[y/2];
    for (x = 0; x < XTFT_SHIP_WIDTH; x++)
    {
      if (val & (1 << (XTFT_SHIP_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
		continue;
        //col = bgColor;
      
        XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
     }
  }
}

void XTft_EraseExplosion(
  Xuint32 BaseAddress,
  Xuint32 BGAddress,
  Xuint32 xu,
  Xuint32 yu)
 {  
  Xuint32 col, x, y;
  Xuint16 val;
  for (y = 0; y < XTFT_EXPLOSION_HEIGHT; y++)
  {
    val = XTft_Explosion[y/2];
    for (x = 0; x < XTFT_EXPLOSION_WIDTH; x++)
    {
		if (yu+y > 330)
			col = XTft_mGetPixel(BGAddress, xu+x, yu+y);
		else
			col = 0;
     XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
    }
  }
}


void XTft_DrawExplosion(
  Xuint32 BaseAddress,
  Xuint32 xu,
  Xuint32 yu,
  Xuint32 fgColor)
{
  Xuint32 col, x, y;
  Xuint16 val;
  for (y = 0; y < XTFT_EXPLOSION_HEIGHT; y++)
  {
    val = XTft_Explosion[y/2];
    for (x = 0; x < XTFT_EXPLOSION_WIDTH; x++)
    {
      if (val & (1 << (XTFT_EXPLOSION_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
	    continue;
      XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
    }
  }
}


void XTft_DrawLetter(Xuint32 BaseAddress, Xuint32 char_index, Xuint32 xu, Xuint32 yu, Xuint32 fgColor){
  Xuint32 col, x, y;
  Xuint16 val;
  for (y = 0; y < XTFT_LETTER_HEIGHT; y++)
  {
    val = XTft_Letters[(Xuint32) char_index][y/2];
    for (x = 0; x < XTFT_LETTER_WIDTH; x++)
    {
      if (val & (1 << (XTFT_LETTER_WIDTH/2 - x/2 - 1)))
        col = fgColor;
      else
	    continue;
      XTft_mSetPixel(BaseAddress, xu+x, yu+y, col);
    }
  }
}