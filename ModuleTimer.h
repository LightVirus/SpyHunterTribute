#pragma once
#include "Module.h"
#include "SDL/include/SDL.h"
#include "Timer.h"

#include <list>
class ModuleTimer :
	public Module
{
public:
	ModuleTimer();
	~ModuleTimer();

	Uint32 getTime();
	int lasttime = 0;
	int finalfps = 0;
	int fpstimercont = 0;
	float deltatime = 0.0f;

	bool Start();
	void StartLoop();
	void EndLoop();
	float CalculateFPS();
	void const FPSMax();
	Timer createtimer(float secs);
	bool UpdateTimers(Timer &time);
	

private:
	std::list<Timer> timerlist;
	Uint32 starttime = 0;
	int fpscont = 0;
	Uint32 frametimer = 0;



};

