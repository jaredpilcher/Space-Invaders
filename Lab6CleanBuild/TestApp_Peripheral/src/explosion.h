#ifndef EXPLOSION_MARKER
#define EXPLOSION_MARKER
#define EXPLOSION_EXPIRE 5
#define TANK_EXPLOSION_EXPIRE 15
#include "TestApp_Memory.h"

typedef struct {
  int x;
  int y;
  int type;
  int active;
  int time_elapsed;
  int score;
  int animation_step;
  int visible;
} explosion;
void drawTankExplosion(explosion new_explosion, int next_frame);
void eraseTankExplosion(explosion old_explosion, int prev_frame);
void eraseExplosion(explosion old_explosion, int prev_frame);
void drawExplosion(explosion new_explosion, int next_frame);
explosion updateExplosion(explosion new_explosion);
explosion newExplosion(explosion temp_explosion, int x, int y);
explosion newShipExplosion(explosion temp_explosion, int x, int y);














#endif
