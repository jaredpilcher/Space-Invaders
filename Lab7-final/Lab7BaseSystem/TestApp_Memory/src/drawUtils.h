#ifndef XTFT_DRAWUTILS_H
#define XTFT_DRAWUTILS_H

#include "xbasic_types.h"

void XTft_FillScreen(Xuint32 BaseAddress, Xuint32 xu, Xuint32 yu, Xuint32 xl, 
                Xuint32 yl, Xuint32 col);

void XTft_DrawAlien(Xuint32 BaseAddress,Xint16 ch,Xuint32 xu,Xuint32 yu,Xuint32 fgColor,
  Xuint32 bgColor);
  

		
#endif

