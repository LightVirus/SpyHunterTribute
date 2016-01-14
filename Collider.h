#pragma once
#include "SDL/include/SDL.h"

//#include <list>

class GameObject;
class Collider
{
public:
	Collider(){}
	~Collider(){}

	
	
	GameObject* parent;
	SDL_Rect localrect;
	SDL_Rect rect;
	SDL_Color color;
	bool deleteme;
	bool cancollide = true;
};

