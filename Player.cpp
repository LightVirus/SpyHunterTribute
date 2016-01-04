#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTimer.h"
#include "ModuleInput.h"
#include <sstream>



Player::Player()
{
}


Player::~Player()
{
}

void Player::SetPlayer(Collider* collider, SDL_Rect cuadro, SDL_Rect cuadrotex, SDL_Texture* Tex)
{
	col = collider;
	Rect = cuadro;
	TextureRect = cuadrotex;
	MainTex = Tex;
}

void Player::Update()
{
	
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if (xvel > 0)
			xvel = 0;
		xvel = xvel - 10;
		if (xvel < -10000)
			xvel = -10000;
	}
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{ 
		if (xvel < 0)
			xvel = 0;
		xvel = xvel + 10 ;
		if (xvel > 10000)
			xvel = 10000;
	}
	else if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	{
		RenderCol = !RenderCol;
	}
	
	else
	{
		xvel = 0;
	}
	
	posp.x = posp.x + (xvel * App->timer->deltatime);
	
	//Collider
	col->rect.x = posp.x - (col->rect.w / 2);
	col->rect.y = posp.y;
}

void Player::OnCollisionEnter(GameObject * ColWith)
{
	LOG("COLLISION WITH PLAYER DETECTED");
}

void Player::RenderGameObj()
{
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posp.x + xoffset, posp.y, &TextureRect);
	}
}