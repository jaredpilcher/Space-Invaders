#include "xparameters.h"
#include "xuartlite_l.h"
#include "xtft_l.h"
#include "xsysace.h"
#include "stdlib.h"

#include "drawUtils.h"
#include "alienCodes.h"

#define FRAME1 0x00000000
#define FRAME2 0x00200000
#define FRAME3 0x00400000
#define FRAME4 0x00800000
//Note: Use 2MB boundaries for your frame address so they will align correctly.

#define TOP_OF_SCREEN 0
#define BOTTOM_OF_SCREEN 480

#define RED 0x00ff0000
#define GREEN 0x0000ff00
#define BLUE 0x000000ff
#define BLACK 0x0
#define WHITE 0x00ffffff

#define MINIMUM_MOVEMENT 4
#define MOVE_DOWN_DISTANCE 14
#define NUMBER_OF_ALIENS 55
#define BULLET_SPEED 4

#define START_X  165
#define START_Y  45

#define SCHMO 2
#define THE_CLAW 4
#define BOB 6

#define IN 1
#define OUT 0

#define RIGHT 1
#define LEFT 0

#define TANK_BULLET_TYPE 7
#define ALIEN_BULLET_ONE 0
#define ALIEN_BULLET_TWO 3

int direction= RIGHT;

typedef struct {
  int x;
  int y;
} coord_object;

typedef struct {
  int x;
  int y;
  int type;
  int active;
  int position;
} bullet;
coord_object tank;
coord_object aliens_coord;
bullet bullets[4];
bullet tank_bullet;

int aliens[55];

void eraseBullet(bullet old_bullet){
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
		XTft_DrawBullet(FRAME1,type,old_bullet.x,old_bullet.y,BLACK,BLACK);
	}
}

void drawBullet(bullet new_bullet){
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
	   xil_printf("active: %d x: %d y: %d\n\r", new_bullet.active, new_bullet.x, new_bullet.y);
		XTft_DrawBullet(FRAME1,type,new_bullet.x,new_bullet.y,WHITE,BLACK);
	}
}

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
// FIX BULLETS LATER
bullet fireBullet(coord_object tank){
	bullet new_bullet;
	new_bullet.x = tank.x + 12;
	new_bullet.y = tank.y - 8;
	new_bullet.type = TANK_BULLET_TYPE;
	new_bullet.active = 1;
	return new_bullet;
}

bullet moveBullet(bullet new_bullet){
	if(new_bullet.type == TANK_BULLET_TYPE){
		new_bullet.y -= BULLET_SPEED;
		if(new_bullet.y <= TOP_OF_SCREEN - 10 ){
		  new_bullet.active = 0;
		}
	} else {
	   new_bullet.position = (new_bullet.position + 1) % 4;
		new_bullet.y += BULLET_SPEED;
		if(new_bullet.y > BOTTOM_OF_SCREEN){
		  new_bullet.active = 0;
		}
	}
	return new_bullet;
}

bullet fireAlienBullet(coord_object new_aliens_coord, int row, int col){
	bullet new_bullet;
	new_bullet.x = new_aliens_coord.x + col*30 + 12;
	new_bullet.y = new_aliens_coord.y + row*30 + 18;
	xil_printf("%d %d\n\r",new_bullet.x, new_bullet.y);
	new_bullet.type = rand() % 2? ALIEN_BULLET_ONE : ALIEN_BULLET_TWO;
	new_bullet.active = 1;
	new_bullet.position = 0;
	return new_bullet;
}
	
void drawBunkers(){
	XTft_DrawBunker(FRAME1,90,335,GREEN,BLACK);
	XTft_DrawBunker(FRAME1,225,335,GREEN,BLACK);
	XTft_DrawBunker(FRAME1,362,335,GREEN,BLACK);
	XTft_DrawBunker(FRAME1,498,335,GREEN,BLACK);
}

void render(coord_object new_aliens_coord, coord_object new_tank, bullet new_tank_bullet, int * aliens, bullet * alien_bullets){
		  drawBunkers();
		  eraseAllAliens(aliens_coord);
		  drawAllAliens(new_aliens_coord, aliens);
		  eraseTank(tank);
		  drawTank(new_tank);
		  eraseBullet(tank_bullet);
		  drawBullet(new_tank_bullet);
		  int i;
		  for(i=0; i<4; i++){
		    eraseBullet(bullets[i]);
			 //xil_printf("%d active: %d x: %d y: %d\n\r", i, alien_bullets[i].active, alien_bullets[i].x, alien_bullets[i].y );
			 if(alien_bullets[i].active){
			   
				drawBullet(alien_bullets[i]);
			 }
		    bullets[i] = alien_bullets[i];
		  }
		  tank = new_tank;
		  tank_bullet = new_tank_bullet;
		  aliens_coord = new_aliens_coord;
}

int main() {
  XTft_mClearScreen(FRAME1, BLACK);
  srand(91745452);
  aliens_coord.x= START_X;
  aliens_coord.y= START_Y;
  int i;
  for(i=0; i<sizeof(aliens);i++){
	aliens[i]=1;
  }
  for(i=0; i<4; i++){
	bullets[i].active = 0;
  }
  
  tank_bullet.active = 0;
  drawAllAliens(aliens_coord, aliens);
  tank.x = 200;
  tank.y = 400;
  drawTank(tank);
  drawBunkers();
  while(1){
    char input;
	 int alien_number;
	 char input2;
	 coord_object new_aliens_coord = aliens_coord;
	 coord_object new_tank = tank;
	 bullet new_bullets[4];
	 new_bullets[0] = bullets[0];
	 new_bullets[1] = bullets[1];
	 new_bullets[2] = bullets[2];
	 new_bullets[3] = bullets[3];
	 bullet new_tank_bullet = tank_bullet;
    read(0,&input,1);
	 switch(input){
		case '4':
		  new_tank = moveLeft(new_tank);
		  break;
		case '6':
		  new_tank = moveRight(new_tank);
		  break;
		case '8':
		  new_aliens_coord = moveAliens(new_aliens_coord);
		  break;
		case '2':
		  read(0,&input2,1);
		  alien_number = 10*(input2 - 48);
		  read(0,&input2,1);
		  alien_number += (input2 - 48);
		  aliens[alien_number] = 0;
		  break;
		case '5':
		  if(new_tank_bullet.active){
		    break;
		  }
		  new_tank_bullet = fireBullet(new_tank);
		  break;
		case '3':
		  for(i = 0; i < 4; i++){
		    if (new_bullets[i].active == 0){
			   break;
			 }
		  }
		  if(i == 4){
			 break;
		  }
		  
		  int alien_number = rand() % 11;
		  int unique = 0;
		  int j;
		  while(!unique){
		    for(j=0; j < 4; j++){
			   xil_printf("Comparing %x and %x\n\r", new_bullets[j].x, alien_number*30 + 12 + new_aliens_coord.x);
				if (
				(new_bullets[j].x == alien_number*30 + 12 + new_aliens_coord.x) &&
				(new_bullets[j].y == new_aliens_coord.y + 4*30 + 18)
				){
					break;
		      }
			 }
			 if (j == 4){
				unique = 1;
			 } else {
				alien_number = rand() % 11;
			 }
		  }
		  
		  new_bullets[i] = fireAlienBullet(new_aliens_coord, 4, alien_number);
		  break;
		case '9':
		  new_tank_bullet = moveBullet(new_tank_bullet);
		  for(i = 0; i < 4; i++){
		    if(new_bullets[i].active){
				new_bullets[i] = moveBullet(new_bullets[i]);
			 }
		  }
		  break;	
	 }
	 render(new_aliens_coord,new_tank, new_tank_bullet, aliens, new_bullets);
  }
  return 0;
}
  