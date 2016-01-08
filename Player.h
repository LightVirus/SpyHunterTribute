#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "Application.h"
#include "ModuleRender.h"
#include "Globals.h"
#include "SDL/include/SDL.h"

class Player :
	public GameObject
{
public:
	Player();
	~Player();

	Collider* col = NULL;
	float turnvel = 100.0f;
	SDL_Rect TextureRect;
	SDL_Rect Rect;
	SDL_Texture* MainTex = NULL;
	SDL_Rect Idle;
	SDL_Rect colidle;
	SDL_Rect Turn1;
	SDL_Rect colturn1;
	SDL_Rect Turn2;
	SDL_Rect colturn2;
	bool derecha = false;
	bool izquierda = false;
	bool RenderCol = false;
	bool boat = false;
	bool outroad = false;
	bool firing = false;
	bool turbo = false;
	void SetPlayer(Collider* collider, SDL_Rect colidlex, SDL_Rect colturn1x, SDL_Rect colturn2x, SDL_Rect Idlex, SDL_Rect Turn1x, SDL_Rect Turn2x, SDL_Texture* Tex);
	void RenderGameObj();
	void Update();
	void OnCollisionEnter(GameObject* ColWith);

	enum PlayerState
	{
		idle,
		turnrigth,
		turnleft,
		dead
	};

	PlayerState ActualState = idle;

};

