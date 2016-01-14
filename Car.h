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
#include "Particle.h"

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
	Timer collidedtime;
	float bikey = 0;
	float bikex = 0;
	ControlState carstate;
	float colldirx = 0.0f;
	float colldiry = 0.0f;

	Particle* CarParticle1 = NULL;
	Particle* CarParticle2 = NULL;

	void Update();
	void RenderGameObj();
	void OnCollisionEnter(Collider* ColWith);

};

