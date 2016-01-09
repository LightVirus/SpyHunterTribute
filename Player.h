#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "Application.h"
#include "ModuleRender.h"
#include "Globals.h"
#include "Timer.h"
#include "SDL/include/SDL.h"
#include "Point.h"

class Player :
	public GameObject
{
public:
	Player();
	~Player();

	Collider* col = NULL;
	float turnvel = 100.0f;
	float yspeed = 0.0f;
	float roadvel = 500.0f;
	float roaddest = 500.0f;
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
	fPoint colOffset;
	float yDest;
	
	bool Colthisframe = false;
	bool Collastframe = false;
	bool RenderCol = false;
	bool boat = false;
	bool firing = false;
	bool turbo = false;
	
	
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

