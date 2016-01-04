#pragma once
#include "SDL/include/SDL.h"
class Timer
{
public:
	Timer()
	{}
	~Timer()
	{}

	Uint32 timerstart = 0;
	Uint32 timepast = 0;
	Uint32 endtime = 1000;
	bool timerended = false;

};

