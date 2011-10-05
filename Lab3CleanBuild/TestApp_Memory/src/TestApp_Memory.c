#include "TestApp_Memory.h"

Timer timers[20];

int direction= RIGHT;
coord_object tank;
coord_object new_tank;
coord_object aliens_coord;
coord_object new_aliens_coord;
coord_object space_ship, new_space_ship;
explosion cur_explosion, new_explosion;
explosion cur_tank_explosion, new_tank_explosion;
explosion ship_explosion, new_ship_explosion;
bullet bullets[4];
bullet new_bullets[4];
bullet tank_bullet;
bullet new_tank_bullet;
int prev_frame;
int next_frame;
unsigned pit_counter;
int bunker_state[4][12];
int bunker_position[4]={90,225,362,498};

XGpio gpPB;

int aliens[55];

void my_pitHandler(void * DataPtr){
   XTime_PITClearInterrupt();
   pit_counter++;
}

void newShip(){
	if(!new_space_ship.active){
		if (rand() % 100 > NEW_SHIP_PROBABILITY)
			return;
		new_space_ship.x=-64;
		new_space_ship.y=45;
		new_space_ship.active=1;
	}
}

explosion newExplosion(explosion temp_explosion, int x, int y){
	if(!temp_explosion.active){
		temp_explosion.x=x;
		temp_explosion.y=y;
		temp_explosion.active=1;
		temp_explosion.time_elapsed=0;
	}
	return temp_explosion;
}

explosion newShipExplosion(explosion temp_explosion, int x, int y){
	if(!temp_explosion.active){
		temp_explosion.x=x;
		temp_explosion.y=y;
		temp_explosion.active=1;
		temp_explosion.time_elapsed=0;
		temp_explosion.score=(rand()%301) + 50;
	}
	return temp_explosion;
}

void updateShip(){
	new_space_ship = moveShip(new_space_ship);
}

void updateAliens(){
	new_aliens_coord = moveAliens(new_aliens_coord,aliens);
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
	if (rand() % 100 > ALIEN_FIRE_PROBABILITY)
		return;
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


void erodeBunker(int bunker_number,int block_number){
	int state = bunker_state[bunker_number][block_number];
	bunker_state[bunker_number][block_number] = (state == 4) ? 4: state + 1;
}

int is_alien_hit(int rel_x, int rel_y){
	int row = rel_y/30;
	int col = rel_x/30;
	int alien_rel_x = rel_x % 30;
	int alien_rel_y = rel_y % 30;
	switch(row){
		case 0:
			if (alien_rel_x > 3 && alien_rel_x < 20 && alien_rel_y < 16){
				return 1;
			}
			break;
		case 1:
		case 2:
			if (alien_rel_y < 16 && alien_rel_x > 1 && alien_rel_x < 24){
				return 1;
			}
			break;
		default:
			if (alien_rel_y < 16 && alien_rel_x < 24){
				return 1;
			}
			break;
	}
	return 0;
}

bullet detectCollision(bullet new_bullet){
	int i;
	// Check bunkers
	if( new_bullet.y > 325 && new_bullet.y < 371){
		for(i = 0; i < 4; i++){
			int x_offset = bunker_position[i];
			int y_offset = 335;
			int x_lower_limit = x_offset -6;
			int x_upper_limit = x_offset + 48;
			if(x_lower_limit < new_bullet.x && new_bullet.x<x_upper_limit){
				int rel_y = new_bullet.y - y_offset;
				int rel_x = new_bullet.x - x_offset;
				int row = rel_y/12;
				int col = rel_x/12;
				int block = row*4 + col;
				if (bunker_state[i][block] != 4){
					erodeBunker(i, block);
					new_bullet.active = 0;
					return new_bullet;
				}
			}
		}
	}
	//  Check aliens
	//  Possible problem - bullets on left side withing 2px would be a miss.  They should be a hit.
	int aliens_x_low = new_aliens_coord.x;
	int aliens_x_high = new_aliens_coord.x + 330;
	int aliens_y_low = new_aliens_coord.y; 
	int aliens_y_high = new_aliens_coord.y + 150;
	if(new_bullet.y > aliens_y_low && new_bullet.y < aliens_y_high && new_bullet.type == TANK_BULLET_TYPE){
		if (new_bullet.x > aliens_x_low && new_bullet.x < aliens_x_high){
			int rel_y = new_bullet.y - aliens_y_low;
			int rel_x = new_bullet.x - aliens_x_low;
			int row = rel_y/30;
			int col = rel_x/30;
			int alien_number = row*11 + col;
			if(aliens[alien_number]){
				if (is_alien_hit(rel_x,rel_y)){
					aliens[alien_number] = 0;
					new_bullet.active = 0;
					new_explosion=newExplosion(new_explosion,new_aliens_coord.x + col*30, new_aliens_coord.y + row*30);
					new_explosion.type=ALIEN_EXPLOSION;
					return new_bullet;
				}
			}
		}
	}
	
	
	
	//  Check tank
	int tank_x_low = new_tank.x;
	int tank_x_high = new_tank.x + 30;
	int tank_y_low = new_tank.y;
	int tank_y_high = new_tank.y + 18;
	if((new_bullet.y > tank_y_low || (new_bullet.y + 10) > tank_y_low) && new_bullet.y < tank_y_high && (new_bullet.type == ALIEN_BULLET_ONE || new_bullet.type == ALIEN_BULLET_TWO)){
		if ((new_bullet.x > tank_x_low || (new_bullet.x + 6) > tank_x_low)&& new_bullet.x < tank_x_high){
		    new_tank.active=0;
			new_bullet.active=0;
			new_tank_explosion=newExplosion(new_tank_explosion,new_tank.x, new_tank.y);
			new_tank_explosion.type=TANK_EXPLOSION;
		}
	}
	
	//  Check Space Ship
	int ship_x_low = new_space_ship.x;
	int ship_x_high = new_space_ship.x + 32;
	int ship_y_low = new_space_ship.y;
	int ship_y_high = new_space_ship.y + 16;
	if(new_bullet.y > tank_y_low && new_bullet.y < tank_y_high){
		if ((new_bullet.x > tank_x_low || (new_bullet.x + 6) > tank_x_low)&& new_bullet.x < tank_x_high){
			new_space_ship.active=0;
			new_bullet.active=0;
			new_ship_explosion=newShipExplosion(new_ship_explosion,new_space_ship.x,new_space_ship.y);
			new_ship_explosion.type = SHIP_EXPLOSION;
		}
	}
	
	
	return new_bullet;
}

void expireExplosion(){
	new_explosion=updateExplosion(new_explosion);
}

void expireTankExplosion(){
	new_tank_explosion=updateExplosion(new_tank_explosion);
	if(!new_tank_explosion.active){
		new_tank.active=1;
	}
}

void moveAllBullets(){
	int i;
	if (new_tank_bullet.active){
		new_tank_bullet = moveBullet(new_tank_bullet);
		new_tank_bullet = detectCollision(new_tank_bullet);
	}
	
	for(i = 0; i < 4; i++){
		if(new_bullets[i].active){
			new_bullets[i] = moveBullet(new_bullets[i]);
			new_bullets[i] = detectCollision(new_bullets[i]);
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
	int cur_x;
	int i;
	int j;
	for(i=0;i<4;i++){
		cur_x= bunker_position[i];
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_0,bunker_state[i][0], cur_x,335,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_1,bunker_state[i][1],cur_x,335,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_1,bunker_state[i][2],cur_x,335,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_2,bunker_state[i][3],cur_x,335,GREEN,BLACK);
		cur_x= bunker_position[i];
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_1,bunker_state[i][4],cur_x,347,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_3,bunker_state[i][5],cur_x,347,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_4,bunker_state[i][6],cur_x,347,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_1,bunker_state[i][7],cur_x,347,GREEN,BLACK);
		cur_x= bunker_position[i];
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_1,bunker_state[i][8],cur_x,359,GREEN,BLACK);
		cur_x+=BLOCK_WIDTH*3;
		XTft_DrawBunkerBlock(frame,BLOCK_TYPE_1,bunker_state[i][11],cur_x,359,GREEN,BLACK);
	}
}

//  NOTE TO US:  render currently takes the global aliens array.  This means we have to erase all aliens, instead of just the ones
//  that were drawn.  The other problem is that we are passing a pointer for alien_bullets, which resides on the previous stack frame.
// If there are any problems, look there first.
void render(){
		  int i;
		  
		  //draw stuff to next frame
		  drawBunkers(next_frame);
		  drawAllAliens(new_aliens_coord, aliens, new_space_ship, next_frame);
		  if(new_tank.active){
			drawTank(new_tank, next_frame);
		  }
		  drawBullet(new_tank_bullet, next_frame);
		  new_tank_explosion.explosion_type=(new_tank_explosion.explosion_type +1)%3;
		  if(new_tank_explosion.active){
			drawTankExplosion(new_tank_explosion,next_frame);
		  }
		  if( new_explosion.active)
			drawExplosion(new_explosion,next_frame);
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
		  //xil_printf("%d %d\n\r", aliens_coord.x, aliens_coord.y);
		  eraseAllAliens(aliens_coord, space_ship, prev_frame);
		  if(tank.active){
			eraseTank(tank, prev_frame);
		  }
		  eraseBullet(tank_bullet, prev_frame);
		  if( cur_explosion.active )
			eraseExplosion(cur_explosion, prev_frame);
		  if( cur_tank_explosion.active )
			eraseTankExplosion(cur_tank_explosion, prev_frame);

		  //copy to global state
		  tank = new_tank;
		  tank_bullet = new_tank_bullet;
		  aliens_coord = new_aliens_coord;
		  space_ship=new_space_ship;
		  cur_explosion=new_explosion;
		  cur_tank_explosion=new_tank_explosion;
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

void pollButtons(){
	Xuint32 data;
	data = XGpio_DiscreteRead(&gpPB, 1);
	// LEFT = 2
	if( ~data & 2 ){
		if(new_tank.active){
			new_tank = moveLeft(new_tank);
		}
	}
	// RIGHT = 1
	if ( ~data & 1 ){
		if(new_tank.active){
			new_tank = moveRight(new_tank);
		}
	}
	// MIDDLE = 16
	if ( ~data & 16 ){
		if(new_tank_bullet.active == 0){
			if(new_tank.active){
				new_tank_bullet = fireBullet(new_tank);
			}
		}
	}
}

int main() {
XCache_EnableICache(0x00000001);
XCache_EnableDCache(0x00000001);
     //XGpio gpLED;

     // Initialise the peripherals
     //XGpio_Initialize(&gpLED, XPAR_LEDS_4BIT_DEVICE_ID);
     XGpio_Initialize(&gpPB, XPAR_PUSHBUTTONS_5BIT_DEVICE_ID);
     // Set the LED peripheral to outputs
     //XGpio_SetDataDirection(&gpLED, 1, 0x00000000);
     // Set the Push Button peripheral to inputs
     XGpio_SetDataDirection(&gpPB, 1, 0x0000001F);
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
  
  cur_explosion.active = 0;
  new_explosion = cur_explosion;
  cur_tank_explosion.active =0;
  cur_tank_explosion.explosion_type=0;
  new_tank_explosion = cur_tank_explosion;
  int i;
  int j;
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
  for(i=0;i<4;i++){
	for(j=0;j<9;j++){
		bunker_state[i][j]=0;
	}
	for(;j<11;j++){
		bunker_state[i][j]=4;
	}
	bunker_state[i][11]=0;
  }
  tank_bullet.active = 0;
  new_tank_bullet = tank_bullet;

  drawAllAliens(aliens_coord, aliens, space_ship, prev_frame);
  tank.x = 200;
  tank.y = 400;
  new_tank = tank;
  drawTank(tank, prev_frame);
  drawBunkers(prev_frame);
  //drawBunkers(next_frame);
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
	timers[1] = newTimer(150, updateAliens);
	timers[2] = newTimer(500, newAlienBullet);
	timers[3] = newTimer(30, moveAllBullets);
	timers[4] = newTimer(25, updateShip);
	timers[5] = newTimer(500, newShip);
	timers[6] = newTimer(20, render);
	timers[7] = newTimer(30, pollButtons);
	timers[8] = newTimer(50, expireExplosion);
	timers[9] = newTimer(50, expireTankExplosion);
	
	int longest_delta = 0;
	  DrawWord("LIVES",400,10,FRAME1, 1);
  DrawWord("LIVES",400,10,FRAME2, 1);
  DrawWord("SCORE",30,10,FRAME1, 1);
  DrawWord("SCORE",30,10,FRAME2, 1);
  while(1){
	new_pit_counter=pit_counter;
	time_delta=new_pit_counter-old_pit_counter;
	if(time_delta != 0){
		if(time_delta > longest_delta){
			longest_delta = time_delta;
			xil_printf("new longest delta %d\n\r",longest_delta);
		}
		for(i=0;i<10;i++){
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
  
