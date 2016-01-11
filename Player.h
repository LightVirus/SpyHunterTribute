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
	Timer firetimer;
	fPoint colOffset;
	float yDest;
	
	bool Colthisframe = false;
	bool Collastframe = false;
	bool RenderCol = false;
	bool boat = false;
	bool deadbool = false;
	bool turbo = false;
	bool gun2fire = false;
	
	
	void SetPlayer(Collider* collider, SDL_Texture* Tex);
	void RenderGameObj();
	void Update();
	void PostUpdate();
	void OnCollisionEnter(GameObject* ColWith);

	enum ControlState
	{
		idle,
		turnrigth,
		turnleft,
		dead
	};


	ControlState ControlActualState = idle;
	item_type CollisionState = null;

};

