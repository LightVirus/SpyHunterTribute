#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "SDL/include/SDL.h"
#include <vld.h>

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned __int32 uint32;


#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);



// Deletes a buffer
#define RELEASE( x ) \
{ \
if (x != nullptr) \
{ \
	delete x; \
	x = nullptr; \
} \
}

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
{  \
if (x != nullptr) \
{ \
	delete[] x; \
	x = nullptr; \
} \
}

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum item_type
{
	null,
	player,
	car,
	mbike,
	heli,
	road,
	sector,
	gun,
	anim,
	oil
};

/*enum controls
{
	Cnoone,
	Crigth,
	Cleft,
	Cup,
	Cdown

};*/

enum SectorType
{
	water,
	big,
	estr,
	estrder,
	estrizq,
	bridge
};

// Configuration -----------
#define SECTOR_END 2000
#define DEBUG_ALPHA 150
#define SCREEN_WIDTH 880
#define SCREEN_HEIGHT 750
#define ROAD_X 200
#define ROAD_Y 13
#define FULLSCREEN false
#define BORDERLESS false
#define RESIZABLE false
#define FULLSCREEN_DESKTOP false
#define VSYNC true
#define FPSLOCK false
#define FPSMAX 50.0f
#define TITLE "SpyHunter by Unai Lujambio"


