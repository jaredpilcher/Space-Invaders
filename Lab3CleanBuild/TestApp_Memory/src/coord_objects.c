#include "TestApp_Memory.h"

void eraseTank(coord_object old_tank){
	XTft_DrawTank(FRAME1,old_tank.x,old_tank.y,BLACK,BLACK);
}
void drawTank(coord_object new_tank){
	XTft_DrawTank(FRAME1,new_tank.x,new_tank.y,GREEN,BLACK);
}

void drawAlien(int x, int y,int type, int frame){
	XTft_DrawAlien(frame,type,x,y,WHITE,BLACK);
}

void eraseAlien(int x, int y,int type, int frame){
	XTft_DrawAlien(frame,type,x,y,BLACK,BLACK);
}

void eraseAllAliens(coord_object aliens) {
	int i;
	for(i=0; i<NUMBER_OF_ALIENS; i++){
	   int col = i % 11;
		int row = i / 11;
		int y = aliens.y + row*30;
		int x = aliens.x + col*30;
		int type;
		int position;
		if ((aliens.x - START_X) % (2*MINIMUM_MOVEMENT)){
			position = IN;
		} else {
			position = OUT;
		}
		if (row == 0){
			type = SCHMO | position;
		} else {
		   type = THE_CLAW | position;
		}
		eraseAlien(x,y,type,FRAME1);
	}
}

void drawAllAliens(coord_object aliens, int * aliens_array) {
	int i;
	for(i=0; i<NUMBER_OF_ALIENS; i++){
		if( ! aliens_array[i]){
			continue;
		}
	   int col = i % 11;
		int row = i / 11;
		int y = aliens.y + row*30;
		int x = aliens.x + col*30;
		int type;
		int position;
		if ((aliens.x - START_X) % (2*MINIMUM_MOVEMENT)){
			position = IN;
		} else {
			position = OUT;
		}
		if (row == 0){
			type = SCHMO | position;
		} else if (row < 3) {
		   type = THE_CLAW | position;
		} else {
			type = BOB | position;
		}
		drawAlien(x,y,type,FRAME1);
	}
}

coord_object moveRight(coord_object aliens) {
	aliens.x += MINIMUM_MOVEMENT;
	return aliens;
}

coord_object moveLeft(coord_object aliens) {
	aliens.x -= MINIMUM_MOVEMENT;
	return aliens;
}

coord_object moveDown(coord_object aliens){
	aliens.y += MOVE_DOWN_DISTANCE;
	return aliens;
}

coord_object moveAliens(coord_object aliens) {
  if (direction==RIGHT){
    if (aliens.x > 640 - (330 + MINIMUM_MOVEMENT)){
	   direction = LEFT;
		return moveDown(aliens);
	 }else{
		return moveRight(aliens);
	 }
  } else {
  	 if (aliens.x < MINIMUM_MOVEMENT){
	   direction = RIGHT;
		return moveDown(aliens);
	 } else {
	   return moveLeft(aliens);
	 }
  }
}
