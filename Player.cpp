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

void Player::SetPlayer(Collider* collider, SDL_Rect colidlex, SDL_Rect colturn1x, SDL_Rect colturn2x, SDL_Rect Idlex, SDL_Rect Turn1x, SDL_Rect Turn2x, SDL_Texture* Tex)
{
	col = collider;
	Rect = colidlex;
	TextureRect = Idlex;
	Idle = Idlex;
	Turn1 = Turn1x;
	Turn2 = Turn2x;
	MainTex = Tex;
	colidle = colidlex;
	colturn1 = colturn1x;
	colturn2 = colturn2x;

}

void Player::Update()
{
	switch (ActualState)
	{
	case Player::idle:
		turnvel = 0;
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
			ActualState = turnleft;
		else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
			ActualState = turnrigth;

		break;

	case Player::turnrigth:
		
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_UP)
		{
			ActualState = idle;
			break;
		}
			
		if (turnvel < 0)
			turnvel = 0;
		turnvel = turnvel + 1000 * App->timer->deltatime;
		if (turnvel > 10000)
			turnvel = 10000;
		break;

	case Player::turnleft:
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_UP)
		{
			ActualState = idle;
			break;
		}
		if (turnvel > 0)
			turnvel = 0;
		turnvel = turnvel - 1000 * App->timer->deltatime;
		if (turnvel < -10000)
			turnvel = -10000;
		break;
	case Player::dead:
		break;
	default:
		break;
	}
	
	
	
	/*if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if (turnvel > 0)
			turnvel = 0;
		turnvel = turnvel - 10;
		if (turnvel < -10000)
			turnvel = -10000;
	}
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{ 
		if (turnvel < 0)
			turnvel = 0;
		turnvel = turnvel + 10 ;
		if (turnvel > 10000)
			turnvel = 10000;
	}*/
	if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	{
		RenderCol = !RenderCol;
	}
	
	
	posp.x = posp.x + (turnvel * App->timer->deltatime);
	
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