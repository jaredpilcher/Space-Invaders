#include "TestApp_Memory.h"
#include "coord_objects.h"

void eraseTank(coord_object old_tank, int prev_frame){
	XTft_DrawTank(prev_frame,old_tank.x,old_tank.y,BLACK,BLACK);
}
void drawTank(coord_object new_tank, int next_frame){
	XTft_DrawTank(next_frame,new_tank.x,new_tank.y,GREEN,BLACK);
}
void eraseShip(coord_object space_ship, int prev_frame){
		XTft_DrawShip(prev_frame,space_ship.x,space_ship.y,BLACK,RED);
}
void drawShip(coord_object new_space_ship,int next_frame){
		XTft_DrawShip(next_frame,new_space_ship.x,new_space_ship.y,RED,BLACK);
}

void drawAlien(int x, int y,int type, int next_frame){
	XTft_DrawAlien(next_frame,type,x,y,WHITE);
}

void eraseAlien(int x, int y,int type, int prev_frame){
	XTft_EraseAlien(prev_frame,FRAME3,type,x,y);
}

void eraseAllAliens(coord_object aliens, coord_object space_ship, int prev_frame) {

	int i;
	if(space_ship.active){
		eraseShip(space_ship,prev_frame);
	}
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
		eraseAlien(x,y,type,prev_frame);
	}
}

void drawAllAliens(coord_object aliens, int * aliens_array, coord_object space_ship, int next_frame) {
	int i;
	if(space_ship.active){
		drawShip(space_ship,next_frame);
	}
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
		drawAlien(x,y,type,next_frame);
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

coord_object moveAliens(coord_object new_aliens_coord, int * aliens) {
  int alien_right_edge;
  int alien_left_edge;
  int i,j;
  for(i = 10; i >=0; i--){
	int col_not_empty = 0;
	for(j=0;j<5;j++){
	  col_not_empty |= aliens[j*11+i];
	}
	if(col_not_empty){
		break;
	}
  }
  // i should never be 0
  alien_right_edge = 30 + i*30;
  for(i = 0; i <11; i++){
	int col_not_empty = 0;
	for(j=0;j<5;j++){
	  col_not_empty |= aliens[j*11+i];
	}
	if(col_not_empty){
		break;
	}
  }
  alien_left_edge = i*30;

  if (direction==RIGHT){
    if (new_aliens_coord.x + alien_right_edge > 640 - MINIMUM_MOVEMENT){
	   direction = LEFT;
		new_aliens_coord = moveDown(new_aliens_coord);
	 }else{
		new_aliens_coord = moveRight(new_aliens_coord);
	 }
  } else {
  	 if (new_aliens_coord.x + alien_left_edge < MINIMUM_MOVEMENT){
	   direction = RIGHT;
		new_aliens_coord = moveDown(new_aliens_coord);
	 } else {
	   new_aliens_coord = moveLeft(new_aliens_coord);
	 }
  }
  return new_aliens_coord;
}

int aliens_landed(coord_object new_aliens_coord, int * aliens){
  int alien_bottom_edge;
  int i,j;
  for(i = 4; i >=0; i--){
	int row_not_empty = 0;
	for(j=0;j<11;j++){
	  row_not_empty |= aliens[i*11+j];
	}
	if(row_not_empty){
		break;
	}
  }
  
  alien_bottom_edge = new_aliens_coord.y + i*30;
  return (alien_bottom_edge + XTFT_ALIEN_HEIGHT > 335 + XTFT_BUNKER_HEIGHT);
}

coord_object moveShip(coord_object new_space_ship){
	new_space_ship.x+=SHIP_MOVEMENT;
	if(new_space_ship.x>640){
		new_space_ship.active=0;
	}
	return new_space_ship;
}