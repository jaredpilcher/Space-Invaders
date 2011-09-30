#ifndef SPACE_INVADERS_TEXT
#define SPACE_INVADERS_TEXT
#include "drawUtils.h"

#define XTFT_LETTER_HEIGHT 10
#define XTFT_LETTER_WIDTH 10

extern Xuint16 XTft_Letters[20][5];
void DrawWord(char * message, int x, int y, int frame);

#endif
