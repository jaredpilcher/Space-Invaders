#ifndef XTFT_DRAWUTILS_H
#define XTFT_DRAWUTILS_H

#include "xbasic_types.h"

void XTft_FillScreen2(Xuint32 BaseAddress, Xuint32 xu, Xuint32 yu, Xuint32 xl, 
                Xuint32 yl, Xuint32 col);

void XTft_DrawAlien(Xuint32 BaseAddress,Xint16 ch,Xuint32 xu,Xuint32 yu,Xuint32 fgColor);
  
void XTft_DrawBullet(Xuint32 BaseAddress, Xuint32 type,Xuint32 xu,Xuint32 yu,Xuint32 fgColor, Xuint32 bgColor);

void XTft_DrawShip(Xuint32 BaseAddress,Xuint32 xu,Xuint32 yu,Xuint32 fgColor,Xuint32 bgColor);
  
void XTft_DrawBunkerBlock(Xuint32 BaseAddress,Xuint32 type,Xuint32 erosion,Xuint32 xu,Xuint32 yu,Xuint32 fgColor,
  Xuint32 bgColor);

void XTft_DrawExplosion(Xuint32 BaseAddress,Xuint32 xu,Xuint32 yu,Xuint32 fgColor);
void XTft_EraseExplosion(Xuint32 BaseAddress,Xuint32 BGAddress,Xuint32 xu,Xuint32 yu);

void XTft_DrawLetter(Xuint32 BaseAddress, Xuint32 char_index, Xuint32 xu, Xuint32 yu, Xuint32 fgColor);
void XTft_DrawTank(Xuint32 BaseAddress,Xuint32 xu,Xuint32 yu,Xuint32 fgColor,Xuint32 bgColor);
void XTft_DrawTankExplosion(Xuint32 BaseAddress,Xuint32 type,Xuint32 xu,Xuint32 yu,Xuint32 fgColor,Xuint32 bgColor);
		
#endif

