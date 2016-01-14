#pragma once
#include "GameObject.h"
#include "Application.h"
#include "ModuleTimer.h"
#include "Timer.h"
#include "ModuleCollider.h"
#include "Collider.h"
#include "Timer.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "Collider.h"

class Car :
	public GameObject
{
public:
	Car(float x, float y, bool colx ,SDL_Texture* maintexx ,item_type typex);
	~Car();
	
	fPoint dest;
	float destspeed;
	float carturn;
	SDL_Texture* maintex = NULL;
	SDL_Rect rect;
	SDL_Rect colrect;
	Collider* col = NULL;
	float bikey = 0;
	float bikex = 0;
	ControlState carstate;

	void Update();
	void RenderGameObj();
	void OnCollisionEnter(Collider* ColWith);

};

