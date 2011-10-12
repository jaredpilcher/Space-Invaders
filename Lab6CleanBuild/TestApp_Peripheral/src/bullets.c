#include "bullets.h"

void eraseBullet(bullet old_bullet, int prev_frame){
	if(old_bullet.active){	   
		int type;
		if (old_bullet.type != TANK_BULLET_TYPE){
			type = old_bullet.type + old_bullet.position;
			if(type == 3  && old_bullet.type == ALIEN_BULLET_ONE){
				type = 1;
			}
		} else {
			type = old_bullet.type;
		}
		XTft_EraseBullet(prev_frame,FRAME3,type,old_bullet.x,old_bullet.y);
	}
}
void drawBullet(bullet new_bullet, int next_frame){
	if (new_bullet.active){
	   int type;
		if (new_bullet.type != TANK_BULLET_TYPE){
			type = new_bullet.type + new_bullet.position;
			if(new_bullet.position == 3  && new_bullet.type == ALIEN_BULLET_ONE){
				type = 1;
			}
		} else {
			type = new_bullet.type;
		}
		XTft_DrawBullet(next_frame,type,new_bullet.x,new_bullet.y,WHITE,BLACK);
	}
}
bullet moveBullet(bullet new_bullet){
	if(new_bullet.type == TANK_BULLET_TYPE){
		new_bullet.y -= BULLET_SPEED;
		if(new_bullet.y <= TOP_OF_SCREEN - 10 ){
		  new_bullet.active = 0;
		}
	} else {
		new_bullet.y += BULLET_SPEED;
		if(new_bullet.y > BOTTOM_OF_SCREEN){
		  new_bullet.active = 0;
		}
	}
	return new_bullet;
}

bullet updateBullet(bullet new_bullet){
	new_bullet.position = (new_bullet.position + 1) % 4;
	return new_bullet;
}