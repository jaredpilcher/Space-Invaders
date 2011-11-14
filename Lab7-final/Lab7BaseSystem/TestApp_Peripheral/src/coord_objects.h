#ifndef SPACE_INVADERS_COORD_OBJECT
#define SPACE_INVADERS_COORD_OBJECT
#include "TestApp_Memory.h"



typedef struct {
  int x;
  int y;
  int active;
} coord_object;

extern int direction;

void eraseTank(coord_object old_tank, int prev_frame);
void drawTank(coord_object new_tank, int next_frame);
void drawAlien(int x, int y,int type, int next_frame);
void eraseAlien(int x, int y,int type, int prev_frame);
void eraseAllAliens(coord_object aliens, coord_object space_ship, int prev_frame);
void drawAllAliens(coord_object aliens, int * aliens_array, coord_object space_ship, int next_frame);
coord_object moveRight(coord_object aliens);
coord_object moveLeft(coord_object aliens);
coord_object moveDown(coord_object aliens);
coord_object moveAliens(coord_object new_aliens_coord, int * aliens);
int aliens_landed(coord_object new_aliens_coord, int * aliens);
coord_object moveShip(coord_object ship);
#endif