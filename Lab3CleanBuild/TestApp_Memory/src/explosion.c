#include "explosion.h"

void eraseExplosion(explosion old_explosion, int prev_frame){
	XTft_EraseExplosion(prev_frame,FRAME3,old_explosion.x, old_explosion.y);
}
void drawExplosion(explosion new_explosion, int next_frame){
	XTft_DrawExplosion(next_frame,new_explosion.x, new_explosion.y, WHITE);
}
explosion updateExplosion(explosion new_explosion){
	new_explosion.time_elapsed++;
	if(new_explosion.time_elapsed==EXPLOSION_EXPIRE){
		new_explosion.time_elapsed=0;
		new_explosion.active=0;
	}
	return new_explosion;
}
