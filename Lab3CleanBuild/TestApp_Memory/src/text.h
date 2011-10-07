#ifndef SPACE_INVADERS_TEXT
#define SPACE_INVADERS_TEXT
#include "drawUtils.h"

#define XTFT_LETTER_HEIGHT 10
#define XTFT_LETTER_WIDTH 10

extern Xuint16 XTft_Letters[30][5];
void DrawWord(char * message, int x, int y, int frame, int color);
void DrawScaledWord(char * message, int x, int y, int frame, int color, int scale);
void drawScore(int score, int frame);
void eraseScore(int score, int frame);
void Draw_Or_Erase_Score(int score, int frame, int color);
#endif
