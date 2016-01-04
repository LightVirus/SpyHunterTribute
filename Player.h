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
	float xvel = 100.0f;
	SDL_Rect TextureRect;
	SDL_Rect Rect;
	SDL_Texture* MainTex = NULL;
	bool derecha = false;
	bool izquierda = false;
	bool RenderCol = false;
	void SetPlayer(Collider* collider, SDL_Rect cuadro, SDL_Rect cuadrotex, SDL_Texture* Tex);
	void RenderGameObj();
	void Update();
	void OnCollisionEnter(GameObject* ColWith);



};

