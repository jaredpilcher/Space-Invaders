#include "xparameters.h"
#include "xuartlite_l.h"
#include "xtft_l.h"
#include "xsysace.h"
#include "stdlib.h"
#include "xexception_l.h"
#include "xgpio.h"
#include "stdio.h"

#include "xutil.h"


#include "drawUtils.h"
#include "alienCodes.h"
#include "bullets.h"
#include "coord_objects.h"
#include "timer.h"
#include "explosion.h"
#include "text.h"

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
#define BULLET_SPEED 8
#define ALIEN_FIRE_PROBABILITY 40
#define NEW_SHIP_PROBABILITY 10

#define SHIP_MOVEMENT 4

#define START_X  165
#define START_Y  100

#define TANK_X 200
#define TANK_Y 400

#define SCHMO 2
#define THE_CLAW 4
#define BOB 6

#define IN 1
#define OUT 0

#define RIGHT 1
#define LEFT 0

#define ALIEN_EXPLOSION 1
#define TANK_EXPLOSION 2
#define SHIP_EXPLOSION 3

#define TANK_BULLET_TYPE 7
#define ALIEN_BULLET_ONE 0
#define ALIEN_BULLET_TWO 3

#define BLOCK_TYPE_0 0
#define BLOCK_TYPE_1 1
#define BLOCK_TYPE_2 2
#define BLOCK_TYPE_3 3
#define BLOCK_TYPE_4 4

#define BLOCK_EROSION_0 0
#define BLOCK_EROSION_1 1
#define BLOCK_EROSION_2 2
#define BLOCK_EROSION_3 3
#define BLOCK_EROSION_4 4

#define BLOCK_WIDTH 12
