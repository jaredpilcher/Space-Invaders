#include "explosion.h"

void eraseExplosion(explosion old_explosion, int prev_frame){
	XTft_EraseExplosion(prev_frame,FRAME3,old_explosion.x, old_explosion.y);
}
void drawExplosion(explosion new_explosion, int next_frame){
	XTft_DrawExplosion(next_frame,new_explosion.x, new_explosion.y, WHITE);
}
void eraseTankExplosion(explosion old_explosion, int prev_frame){
	XTft_DrawTankExplosion(prev_frame,old_explosion.animation_step,old_explosion.x,old_explosion.y,BLACK,BLACK);
}
void drawTankExplosion(explosion new_explosion, int next_frame){
	XTft_DrawTankExplosion(next_frame,new_explosion.animation_step,new_explosion.x,new_explosion.y,GREEN,BLACK);
}
void eraseShipExplosion(explosion old_explosion, int prev_frame){
	char mess[4];
	int score = old_explosion.score;
	mess[0] = (score / 100) + 48;
	mess[1] = (score % 100) / 10 + 48;
	mess[2] = (score % 10) + 48;
	
	DrawWord(mess, old_explosion.x, old_explosion.y, prev_frame, 0);
}

void drawShipExplosion(explosion new_explosion, int next_frame){
	char mess[] = "000"; 
	mess[3]=0;
	int score = new_explosion.score;
	mess[0] = (score / 100) + 48;
	mess[1] = (score % 100) / 10 + 48;
	mess[2] = (score % 10) + 48;

	DrawWord(mess, new_explosion.x, new_explosion.y, next_frame, 1);
}
	

explosion updateExplosion(explosion new_explosion){
	new_explosion.time_elapsed++;
	if(new_explosion.type==ALIEN_EXPLOSION){
		if(new_explosion.time_elapsed==EXPLOSION_EXPIRE){
			new_explosion.time_elapsed=0;
			new_explosion.active=0;
		}
	}else if(new_explosion.type==SHIP_EXPLOSION){
		new_explosion.animation_step+=1;
		switch(new_explosion.animation_step){
			case 0:
			case 2:
			case 4:
			case 6:
			case 8:
				new_explosion.visible = 0;
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 9:
			case 10:
			case 11:
			case 12:
			    new_explosion.visible = 1;
				break;
			default:
				new_explosion.time_elapsed=0;
				new_explosion.active = 0;
				new_explosion.visible = 0;
				new_explosion.animation_step = 0;
		}
	}else{
		new_explosion.animation_step=(new_explosion.animation_step +1)%3;
		if(new_explosion.time_elapsed==TANK_EXPLOSION_EXPIRE){
			new_explosion.time_elapsed=0;
			new_explosion.active=0;
			new_explosion.animation_step=0;
		}
	}
	
	return new_explosion;
}
