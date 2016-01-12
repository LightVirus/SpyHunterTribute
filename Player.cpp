#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTimer.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModuleSound.h"
#include "Particle.h"
#include "GameObject.h"
#include "SDL/include/SDL.h"
#include <sstream>


Player::Player()
{
	Idle = { 138,256,30,44 };
	colidle = { 0,0,26,46 };
	Turn1R = { 101,263,32,43 };
	Turn1L = { 101,307,32,43 };
	colturn1 = { 0,0,32,43 };
	deadrect = { 0,365,32,32 };
	resspawn.endtime = 7600;
	roadsound.endtime = 100;
	resspawn.Reset();
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
	//Movement
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
		if (posp.y < (SCREEN_HEIGHT / 2) + 150)
		{
			if (turnvel < 0)
				turnvel = 0;
			turnvel = turnvel + 2000 * App->timer->deltatime;
			if (turnvel > 10000)
				turnvel = 10000;


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
		if (posp.y < (SCREEN_HEIGHT / 2) + 150)
		{
			if (turnvel > 0)
				turnvel = 0;
			turnvel = turnvel - 2000 * App->timer->deltatime;
			if (turnvel < -10000)
				turnvel = -10000;


			TextureRect = Turn1L;
			ColRect = colturn1;
			xoffset = -16;
		}
		
		
		break;

	case Player::dead:
		if (!deadbool)
		{
			App->scene->CreateParticle(0, 0, this, false, ModuleScene::boom, false);
			deadbool = true;
			col->cancollide = false;
			resspawn.Start();
			App->sound->PlayMusic(App->scene->deadmusic ,-1);
		}
		
		if (Poil1 != NULL)
		{
			Poil1->deleteme = true;
			Poil1 = NULL;
		}
		if (Pgun1 != NULL)
		{
			Pgun1->deleteme = true;
			Pgun1 = NULL;
		}
		turnvel = 0;
		roaddest = 0.0f;
		yDest = (SCREEN_HEIGHT / 2) + 150;
		TextureRect = deadrect;
		if (resspawn.UpdateTimer())
		{
			deadbool = false;
			posp.x = SCREEN_WIDTH / 2;
			ControlActualState = idle;
			resspawn.Start();
			deadtimer.Reset();
			App->sound->PlayMusic(App->scene->music1, -1);
		}
		break;
	}
	if (!deadbool && resspawn.timepast != -1)
	{
		if (resspawn.UpdateTimer())
		{
			col->cancollide = true;
			resspawn.Reset();
		}
	}
	
	
	//Speed and destination of x
	if (ControlActualState != dead)
	{
		if (App->input->GetMouseButtonDown(SDL_BUTTON_RIGHT) == KEY_DOWN)
		{
			turbo = !turbo;
		}
		if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		{
			yspeed += 10.0f * App->timer->deltatime;
			if (yspeed >= 1.0f)
				yspeed = 1.0f;
		}
		else
		{
			yspeed -= 10.0f * App->timer->deltatime;
			if (yspeed <= 0.0f)
				yspeed = 0.0f;
		}

		if (yspeed >= 0.5f)
		{
			if (!turbo)
			{
				yDest = (SCREEN_HEIGHT / 2) - 50;
				roaddest = 500.0f;
			}
				
			else if (posp.y < (SCREEN_HEIGHT / 2) + 150)
			{
				yDest = (SCREEN_HEIGHT / 2) - 170;
				roaddest = 1300.0f;
			}
			
		}
		else
		{
			yDest = (SCREEN_HEIGHT / 2) + 180;
			roaddest = 0.0f;
		}

	
	}
	fPoint tempdes;
	tempdes.SetToZero();
	tempdes.y = yDest;
	tempdes.x = posp.x;
	posp.NextPoint(tempdes, 1 * App->timer->deltatime);

	fPoint temproad;
	temproad.SetToZero();
	temproad.y = roaddest;
	fPoint actroad;
	actroad.SetToZero();
	actroad.y = roadvel;
	actroad.NextPoint(temproad, 1 * App->timer->deltatime);
	roadvel = actroad.y;
	
	//Gun fire
	if (ControlActualState != dead)
	{
		
			if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT)
			{
				if (Pgun1 == NULL)
				{
					Pgun1 = App->scene->CreateParticle(0, 0, this, true, ModuleScene::gun1, false);
					firetimer.Start();
				}
					
				else
				{
					
					if (firetimer.UpdateTimer())
					{
						App->scene->CreateParticle(posp.x, posp.y - 35, NULL, true, ModuleScene::gun2, gun2fire);
						gun2fire = !gun2fire;
						firetimer.Start();
					}
					
				}
			}
			else if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP)
			{
				if (Pgun1 != NULL)
				{
					Pgun1->deleteme = true;
					Pgun1 = NULL;
					firetimer.Reset();
				}
				
			}
			//Oil fire
			if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
			{
				if (Poil1 == NULL)
				{
					Poil1 = App->scene->CreateParticle(0, 30, this, false, ModuleScene::oil1, false);
					oiltimer.Start();
				}

				else
				{

					if (oiltimer.UpdateTimer())
					{
						App->scene->CreateParticle(posp.x, posp.y + 35, NULL, true, ModuleScene::oil2, false);
						oiltimer.Start();
					}

				}
			}
			else if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP)
			{
				if (Poil1 != NULL)
				{
					Poil1->deleteme = true;
					Poil1 = NULL;
					oiltimer.Reset();
				}

			}
	}
	
	
		//Collider Rendering
	if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	{
		RenderCol = !RenderCol;
	}
		//God Mode
	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_DOWN)
	{
		godmode = !godmode;
	}
	if (godmode)
	{
		if (god1 == NULL)
		{
			god1 = App->scene->CreateParticle(100, 30, NULL, false, ModuleScene::god, false);
			god2 = App->scene->CreateParticle(SCREEN_WIDTH - 100, 30, NULL, false, ModuleScene::god, false);
			col->cancollide = false;
		}
	}
	else
	{
		if (god1 != NULL)
		{
			god1->deleteme = true;
			god2->deleteme = true;
			god1 = NULL;
			god2 = NULL;
			col->cancollide = true;
		}
	}

	posp.x = posp.x + (turnvel * App->timer->deltatime);
	if (posp.x < 216)
	{
		posp.x = 216;
		TextureRect = Idle;
	}
		
	if (posp.x > 663)
	{
		posp.x = 663;
		TextureRect = Idle;
	}
		
	
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
		
		if (ControlActualState != dead)
		{
			if (CollisionState != road)
			{
				roadsound.Start();
				App->sound->PlaySoundE(App->scene->roadoutSE);
				deadtimer.createtimer(0.75);
				CollisionState = road;
			}
			else
			{
				if (roadsound.UpdateTimer())
				{
					App->sound->PlaySoundE(App->scene->roadoutSE);
					roadsound.Start();
				}

				deadtimer.UpdateTimer();
				if (deadtimer.timerended)
				{
					deadtimer.Reset();
					roadsound.Reset();
					ControlActualState = dead;
				}
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