#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "Point.h"
#include "Timer.h"
#include "SDL/include/SDL.h"

class Collider;
class Application;
class ModuleRender;
class Particle;
class ModuleScene;



class Player : public GameObject
{
public:
	Player();
	~Player();

	Collider* col = NULL;
	float turnvel = 100.0f;
	float yspeed = 0.0f;
	float roadvel = 0.0f;
	float roaddest = 0.0f;
	Particle* Pgun1 = NULL;
	Particle* Poil1 = NULL;
	Particle* god1 = NULL;
	Particle* god2 = NULL;

	SDL_Rect TextureRect;
	SDL_Rect ColRect;
	SDL_Texture* MainTex = NULL;
	SDL_Rect Idle;
	SDL_Rect colidle;
	SDL_Rect Turn1R;
	SDL_Rect Turn1L;
	SDL_Rect colturn1;
	SDL_Rect deadrect;
	Timer deadtimer;
	Timer resspawn;
	Timer firetimer;
	Timer oiltimer;
	Timer roadsound;
	fPoint colOffset;
	float yDest = 0.0f;
	
	bool Colthisframe = false;
	bool Collastframe = false;
	bool RenderCol = false;
	bool boat = false;
	bool deadbool = false;
	bool turbo = false;
	bool gun2fire = false;
	bool godmode = false;
	int lifes = -1;
	
	
	void SetPlayer(Collider* collider, SDL_Texture* Tex);
	void RenderGameObj();
	void Update();
	void PostUpdate();
	void OnCollisionEnter(Collider* ColWith);

	


	ControlState ControlActualState = idle;
	item_type CollisionState = null;

};

