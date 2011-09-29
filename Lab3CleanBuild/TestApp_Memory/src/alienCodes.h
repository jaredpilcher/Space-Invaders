/******************************************************************************/
#ifndef XTFT_ALIENCODE_H
#define XTFT_ALIENCODE_H

#include "xbasic_types.h"

#define XTFT_ALIEN_WIDTH       24
#define XTFT_ALIEN_HEIGHT      18

#define XTFT_TANK_WIDTH			30
#define XTFT_TANK_HEIGHT		18

#define XTFT_BULLET_WIDTH		6
#define XTFT_BULLET_HEIGHT		10

#define XTFT_BUNKER_WIDTH		48
#define XTFT_BUNKER_HEIGHT		36

#define XTFT_BUNKER_BLOCK_HEIGHT 12
#define XTFT_BUNKER_BLOCK_WIDTH 12

#define XTFT_SHIP_HEIGHT 16
#define XTFT_SHIP_WIDTH 32

extern Xuint16 XTft_SpaceShip[8];	
extern Xuint16 XTft_vidAliens[8][9];
extern Xuint16 XTft_tank[9];
extern Xuint16 XTft_bullets[8][5];
extern Xuint16 XTft_BunkerBlocks[5][5][6];
	
#endif
