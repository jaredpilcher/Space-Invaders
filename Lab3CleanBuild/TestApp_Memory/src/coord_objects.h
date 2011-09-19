#ifndef SPACE_INVADERS_COORD_OBJECT
#define SPACE_INVADERS_COORD_OBJECT
#include "TestApp_Memory.h"
typedef struct {
  int x;
  int y;
} coord_object;

extern int direction;

void eraseTank(coord_object old_tank);
void drawTank(coord_object new_tank);
void drawAlien(int x, int y,int type, int frame);
void eraseAlien(int x, int y,int type, int frame);
void eraseAllAliens(coord_object aliens);
void drawAllAliens(coord_object aliens, int * aliens_array);
coord_object moveRight(coord_object aliens);
coord_object moveLeft(coord_object aliens);
coord_object moveDown(coord_object aliens);
coord_object moveAliens(coord_object aliens);
#endif
