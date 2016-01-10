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
	
	void createtimer(float sec)
	{
		endtime = Uint32(sec * 1000);
		timerstart = SDL_GetTicks();
	}
	bool UpdateTimer()
	{
		if (!timerended)
		{
			timepast = SDL_GetTicks() - timerstart;
			if (timepast >= endtime)
			{
				timerended = true;
			}
		}
		return timerended;

	}
	void Reset()
	{
		timerstart = 0;
		timepast = -1;
		timerended = false;
	}
	void Start()
	{
		timerstart = SDL_GetTicks();
		timepast = 0;
		timerended = false;
	}
};

