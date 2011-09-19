#ifndef SPACE_INVADER_BULLETS
#define SPACE_INVADER_BULLETS
#include "TestApp_Memory.h"
typedef struct {
  int x;
  int y;
  int type;
  int active;
  int position;
} bullet;

void eraseBullet(bullet old_bullet);
void drawBullet(bullet new_bullet);
bullet moveBullet(bullet new_bullet);

#endif
