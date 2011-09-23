#include "TestApp_Memory.h"

Timer timers[10];

int direction= RIGHT;
coord_object tank;
coord_object new_tank;
coord_object aliens_coord;
coord_object new_aliens_coord;
bullet bullets[4];
bullet new_bullets[4];
bullet tank_bullet;
bullet new_tank_bullet;
int prev_frame;
int next_frame;
unsigned pit_counter;


int aliens[55];

void my_pitHandler(void * DataPtr){
   XTime_PITClearInterrupt();
   pit_counter++;
}
bullet fireBullet(coord_object tank){
	bullet new_bullet;
	new_bullet.x = tank.x + 12;
	new_bullet.y = tank.y - 8;
	new_bullet.type = TANK_BULLET_TYPE;
	new_bullet.active = 1;
	return new_bullet;
}

bullet fireAlienBullet(coord_object new_aliens_coord, int row, int col){
	//xil_printf("fire bullet: %d, %d", row, col);
	bullet new_bullet;
	new_bullet.x = new_aliens_coord.x + col*30 + 12;
	new_bullet.y = new_aliens_coord.y + row*30 + 18;
	new_bullet.type = rand() % 2? ALIEN_BULLET_ONE : ALIEN_BULLET_TWO;
	new_bullet.active = 1;
	new_bullet.position = 0;
	return new_bullet;
}

void newAlienBullet(){
	int i;
	// find available bullet
	for(i = 0; i < 4; i++){
		if (new_bullets[i].active == 0){
			break;
		}
	}
	// if all bullets are on screen, return
	if(i == 4){
		return;
	}
	// save which bullet we are using
	int alien_bullet = i;
	// pick a column to shoot from
	int col_number = rand() % 11;
	// traverse up column to find first live alien
	for(i = 4; i >=0; i--){
		if(aliens[i*11+col_number]){
			new_bullets[alien_bullet]=fireAlienBullet(new_aliens_coord, i, col_number);
			return;
		}
	}
}

void moveAllBullets(){
	int i;
	new_tank_bullet = moveBullet(new_tank_bullet);
	for(i = 0; i < 4; i++){
		if(new_bullets[i].active){
			new_bullets[i] = moveBullet(new_bullets[i]);
		}
	}
}
void updateAllBullets(){
	int i;
	for(i = 0; i < 4; i++){
		if(new_bullets[i].active){
			new_bullets[i] = updateBullet(new_bullets[i]);
		}
	}
}
void drawBunkers(int frame){
	XTft_DrawBunker(frame,90,335,GREEN,BLACK);
	XTft_DrawBunker(frame,225,335,GREEN,BLACK);
	XTft_DrawBunker(frame,362,335,GREEN,BLACK);
	XTft_DrawBunker(frame,498,335,GREEN,BLACK);
}

//  NOTE TO US:  render currently takes the global aliens array.  This means we have to erase all aliens, instead of just the ones
//  that were drawn.  The other problem is that we are passing a pointer for alien_bullets, which resides on the previous stack frame.
// If there are any problems, look there first.
void render(){
		  int i;
		  
		  //draw stuff to next frame
		  drawAllAliens(new_aliens_coord, aliens, next_frame);
		  drawTank(new_tank, next_frame);
		  drawBullet(new_tank_bullet, next_frame);
		  for(i=0; i<4; i++){
			 if(new_bullets[i].active){
				drawBullet(new_bullets[i], next_frame);
			 }

		  }
		  
		  //switch frame
		  XIo_Out32(XPAR_VGA_FRAMEBUFFER_DCR_BASEADDR, next_frame);
		  
		  //erase stuff from previous frame
		  for(i=0; i<4; i++){
		    eraseBullet(bullets[i], prev_frame);
		  }
		  eraseAllAliens(aliens_coord, prev_frame);
		  eraseTank(tank, prev_frame);
		  eraseBullet(tank_bullet, prev_frame);

		  //copy to global state
		  tank = new_tank;
		  tank_bullet = new_tank_bullet;
		  aliens_coord = new_aliens_coord;
		  for(i=0; i < 4; i++){
		  		    bullets[i] = new_bullets[i];
		  }
		  
		  //swap frame variables
		  prev_frame^=next_frame;
		  next_frame^=prev_frame;
		  prev_frame^=next_frame;
}
void initialize_frame(int frame){
  XTft_mClearScreen(frame, BLACK);
}

void helloWorld(){
  xil_printf("Hello World %x\r\n");
}

int main() {
XCache_EnableICache(0x00000001);
XCache_EnableDCache(0x00000001);
  pit_counter = 0;
  prev_frame = FRAME1;
  next_frame = FRAME2;
  initialize_frame(prev_frame);
  initialize_frame(next_frame);
  initialize_frame(FRAME3);
  srand(91745452);
  aliens_coord.x= START_X;
  aliens_coord.y= START_Y;
  new_aliens_coord = aliens_coord;
  int i;
  for(i=0; i<sizeof(aliens);i++){
	aliens[i]=1;
  }
  //aliens[46]=0;
  //aliens[54]=0;
  //aliens[50]=0;
  //aliens[39]=0;
  for(i=0; i<4; i++){
	bullets[i].active = 0;
  }
  for(i=0; i<4; i++){
	new_bullets[i] = bullets[i];
  }
  
  tank_bullet.active = 0;
  new_tank_bullet = tank_bullet;
  drawAllAliens(aliens_coord, aliens, prev_frame);
  tank.x = 200;
  tank.y = 400;
  new_tank = tank;
  drawTank(tank, prev_frame);
  drawBunkers(prev_frame);
  drawBunkers(next_frame);
  drawBunkers(FRAME3);
  	void * data;
	XExceptionHandler pithandler = &my_pitHandler;
	XExc_Init();
	XExc_RegisterHandler(XEXC_ID_PIT_INT, pithandler,
                          data);
	XTime_PITEnableAutoReload();
	XTime_PITSetInterval(100000);
	XExc_mEnableExceptions(XEXC_ALL);
	XTime_PITEnableInterrupt(); 
	XTime_PITClearInterrupt();
	unsigned alien_counter = 0;
	unsigned old_pit_counter = 0;
	unsigned new_pit_counter = 0;
	unsigned time_delta=0;

	timers[0] = newTimer(50, updateAllBullets);
	timers[1] = newTimer(150, moveAliens);
	timers[2] = newTimer(1000, newAlienBullet);
	timers[3] = newTimer(30, moveAllBullets);
	timers[4] = newTimer(50, render);
	int longest_delta = 0;
  while(1){
	new_pit_counter=pit_counter;
	time_delta=new_pit_counter-old_pit_counter;
	if(time_delta != 0){
		if(time_delta > longest_delta){
			longest_delta = time_delta;
			xil_printf("new longest delta %d\n\r",longest_delta);
		}
		for(i=0;i<5;i++){
			incTimer(&timers[i],time_delta);
		}
	}
	old_pit_counter=new_pit_counter;
  }
  return 0;
}

// prev_frame = FRAME1;
  // next_frame = FRAME2;
  // initialize_frame(prev_frame);
  // initialize_frame(next_frame);
  // initialize_frame(FRAME3);
  // srand(91745452);
  // aliens_coord.x= START_X;
  // aliens_coord.y= START_Y;
  // int i;
  // for(i=0; i<sizeof(aliens);i++){
	// aliens[i]=1;
  // }
  // for(i=0; i<4; i++){
	// bullets[i].active = 0;
  // }
  
  // tank_bullet.active = 0;
  // drawAllAliens(aliens_coord, aliens, prev_frame);
  // tank.x = 200;
  // tank.y = 400;
  // drawTank(tank, prev_frame);
  // drawBunkers(prev_frame);
  // drawBunkers(next_frame);
  // drawBunkers(FRAME3);
  // while(1){
    // char input;
	 // int alien_number;
	 // char input2;
	 // coord_object new_aliens_coord = aliens_coord;
	 // coord_object new_tank = tank;
	 // bullet new_bullets[4];
	 // new_bullets[0] = bullets[0];
	 // new_bullets[1] = bullets[1];
	 // new_bullets[2] = bullets[2];
	 // new_bullets[3] = bullets[3];
	 // bullet new_tank_bullet = tank_bullet;
    // read(0,&input,1);
	 // switch(input){
		// case '4':
		  // new_tank = moveLeft(new_tank);
		  // break;
		// case '6':
		  // new_tank = moveRight(new_tank);
		  // break;
		// case '8':
		  // new_aliens_coord = moveAliens(new_aliens_coord);
		  // break;
		// case '2':
		  // read(0,&input2,1);
		  // alien_number = 10*(input2 - 48);
		  // read(0,&input2,1);
		  // alien_number += (input2 - 48);
		  // aliens[alien_number] = 0;
		  // break;
		// case '5':
		  // if(new_tank_bullet.active){
		    // break;
		  // }
		  // new_tank_bullet = fireBullet(new_tank);
		  // break;
		// case '3':
		  // for(i = 0; i < 4; i++){
		    // if (new_bullets[i].active == 0){
			   // break;
			 // }
		  // }
		  // if(i == 4){
			 // break;
		  // }
		  
		  // int alien_number = rand() % 11;
		  // int unique = 0;
		  // int j;
		  // while(!unique){
		    // for(j=0; j < 4; j++){
				// if (
				// (new_bullets[j].x == alien_number*30 + 12 + new_aliens_coord.x) &&
				// (new_bullets[j].y == new_aliens_coord.y + 4*30 + 18)
				// ){
					// break;
		      // }
			 // }
			 // if (j == 4){
				// unique = 1;
			 // } else {
				// alien_number = rand() % 11;
			 // }
		  // }
		  
		  // new_bullets[i] = fireAlienBullet(new_aliens_coord, 4, alien_number);
		  // break;
		// case '9':
		  // new_tank_bullet = moveBullet(new_tank_bullet);
		  // for(i = 0; i < 4; i++){
		    // if(new_bullets[i].active){
				// new_bullets[i] = moveBullet(new_bullets[i]);
			 // }
		  // }
		  // break;	
	 // }
	 // render(new_aliens_coord,new_tank, new_tank_bullet, aliens, new_bullets);
  // }
  
