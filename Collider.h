#pragma once
#include "SDL/include/SDL.h"
#include "GameObject.h"
//#include <list>
class Collider
{
public:
	Collider(){}
	~Collider(){}
	
	GameObject *parent;
	//list<Collider*> lastcollisions;
	SDL_Rect localrect;
	SDL_Rect rect;
	SDL_Color color;
	bool deleteme;
};

