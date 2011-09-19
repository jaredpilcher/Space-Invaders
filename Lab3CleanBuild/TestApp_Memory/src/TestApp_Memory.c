#include "TestApp_Memory.h"
#include "bullets.h"

int direction= RIGHT;
coord_object tank;
coord_object aliens_coord;
bullet bullets[4];
bullet tank_bullet;

int aliens[55];

bullet fireBullet(coord_object tank){
	bullet new_bullet;
	new_bullet.x = tank.x + 12;
	new_bullet.y = tank.y - 8;
	new_bullet.type = TANK_BULLET_TYPE;
	new_bullet.active = 1;
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
  
