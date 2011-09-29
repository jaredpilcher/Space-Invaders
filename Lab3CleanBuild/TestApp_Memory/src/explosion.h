#ifndef EXPLOSION_MARKER
#define EXPLOSION_MARKER
#define EXPLOSION_EXPIRE 5
#include "TestApp_Memory.h"

typedef struct {
  int x;
  int y;
  int type;
  int active;
  int time_elapsed;
} explosion;

void eraseExplosion(explosion old_explosion, int prev_frame);
void drawExplosion(explosion new_explosion, int next_frame);
explosion updateExplosion(explosion new_explosion);














#endif
