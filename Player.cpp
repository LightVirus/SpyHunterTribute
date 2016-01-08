#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTimer.h"
#include "ModuleInput.h"
#include <sstream>



Player::Player()
{
	 Idle = { 138,256,30,44 };
	 colidle = { 0,0,26,46 };
	 Turn1R = { 101,263,32,43 };
	 Turn1L = { 101,307,32,43 };
	 colturn1 = { 0,0,32,43 };
}


Player::~Player()
{
}

void Player::SetPlayer(Collider* collider, SDL_Texture* Tex)
{
	col = collider;
	MainTex = Tex;
}

void Player::Update()
{
	switch (ControlActualState)
	{
	case Player::idle:
		turnvel = 0;
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
			ControlActualState = turnleft;
		else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
			ControlActualState = turnrigth;

		TextureRect = Idle;
		ColRect = colidle;
		xoffset = -15;

		break;

	case Player::turnrigth:
		
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_UP)
		{
			ControlActualState = idle;
			break;
		}
			
		if (turnvel < 0)
			turnvel = 0;
		turnvel = turnvel + 1000 * App->timer->deltatime;
		if (turnvel > 10000)
			turnvel = 10000;

		if (turnvel > 500)
		{
			TextureRect = Turn1R;
			ColRect = colturn1;
			xoffset = -16;
		}

		break;

	case Player::turnleft:
		
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_UP)
		{
			ControlActualState = idle;
			break;
		}
		if (turnvel > 0)
			turnvel = 0;
		turnvel = turnvel - 1000 * App->timer->deltatime;
		if (turnvel < -10000)
			turnvel = -10000;

		if (turnvel < -500)
		{
			TextureRect = Turn1L;
			ColRect = colturn1;
			xoffset = -16;
		}
		break;

	case Player::dead:
		turnvel = 0;
		LOG("DEAD");
		break;
	default:
		break;
	}
	
	
	
	
	//Collider Rendering
	if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	{
		RenderCol = !RenderCol;
	}
	
	
	/*// DEBUG ------------------------------------------------------------------------------------
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN)
	{
		TextureRect = Turn1R;
		ColRect = colturn1;
		xoffset = -16;
	}
	else if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
	{
		TextureRect = Turn2L;
		ColRect = colturn2;
		xoffset = -26.5;
	}
	else if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
	{
		TextureRect = Turn2R;
		ColRect = colturn2;
		xoffset = -26.5;
	}
	else if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		TextureRect = Turn1L;
		ColRect = colturn1;
		xoffset = -16;
	}
	else if (App->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
	{
		TextureRect = Idle;
		ColRect = colidle;
		xoffset = -15;
	}*/
	
	
	
	posp.x = posp.x + (turnvel * App->timer->deltatime);
	
	//Collider
	col->rect = ColRect;
	col->rect.x = posp.x - (col->rect.w / 2);
	col->rect.y = posp.y;
	Colthisframe = false;
	if (!Collastframe)
		CollisionState = null;
}

void Player::PostUpdate()
{
	Collastframe = Colthisframe;
}

void Player::OnCollisionEnter(GameObject * ColWith)
{
	Colthisframe = true;
	switch (ColWith->type)
	{
	case road:
		if (CollisionState != road)
		{
			deadtimer.createtimer(0.75);
			CollisionState = road;
		}
		else
		{
			deadtimer.UpdateTimer();
			if (deadtimer.timerended)
			{
				ControlActualState = dead;
			}
		}
		

	
	}
}

void Player::RenderGameObj()
{
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posp.x + xoffset, posp.y + yoffset, &TextureRect);
	}
}