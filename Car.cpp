#include "Car.h"
#include "ModuleScene.h"
#include "Player.h"
#include "Collider.h"
#include "GameObject.h"


Car::Car(float x, float y, bool colx, SDL_Texture* maintexx, item_type typex)
{
	
	posp.x = x;
	posp.y = y;
	dest.x = x;
	dest.y = y;
	type = typex;
	maintex = maintexx;
	
	if (type == car)
	{
		rect = { 192,182,28,44 };
		colrect = { 0,0,25,41 };
		carturn = 30;
		xoffset = -13;
		CarParticle1 = App->scene->CreateParticle(-15, 10, this, true, ModuleScene::sharp, true);
		CarParticle2 = App->scene->CreateParticle(15, 10, this, true, ModuleScene::sharp, false);
		CarParticle1->col->type = enemyweapon;
		CarParticle2->col->type = enemyweapon;
	}
	else if (type == mbike)
	{
		rect = { 340,180,23,32 };
		colrect = { 0,0,19,32 };
		xoffset = -9;
		srand(SDL_GetTicks());
		int random = rand() % 575 + 76;
		bikey = random;
		srand(SDL_GetTicks());
		random = rand() % 500 + 280;
		bikex = random;
	}
	if (colx)
		col = App->collider->CreateCol(colrect, car, this);
	carstate = idle;
	collidedtime.endtime = 150;

	

}


Car::~Car()
{
	col->deleteme = true;
	col = NULL;
	if (CarParticle1 != NULL)
	{
		CarParticle1->deleteme = true;
		CarParticle2->deleteme = true;
		CarParticle1 = NULL;
		CarParticle2 = NULL;
	}
}

void Car::Update()
{
	switch (carstate)
	{
	case idle:
	{
		//Calculate Y
		int roaddest = (int)App->scene->MainPlayer.roaddest;
		switch (roaddest)
		{
		case 0:
		{
			dest.y = -250;
			destspeed = 0.5 * App->timer->deltatime;
			break;
		}
		case 500:
		{
			if (type == car)
			{
				dest.y = App->scene->MainPlayer.posp.y;
			}
			else if (type == mbike)
			{
				dest.y = bikey;
			}
			destspeed = 0.25f * App->timer->deltatime;
			break;
		}
		case 1300:
		{
			dest.y = SCREEN_HEIGHT + 150;
			destspeed = 0.5 * App->timer->deltatime;
			break;
		}

		default:
			break;
		}

		//Calculate x
		if (type == mbike)
		{
			dest.x = bikex;
		}
		if (type == car)
		{
			dest.x = App->scene->MainPlayer.posp.x + carturn;
		}



		posp.NextPoint(dest, destspeed);
		if (posp.x > 715 || posp.x < 155)
			deleteme = true;
		if (posp.y < -230 || posp.y > 830)
			deleteme = true;
		break;
	}
	case dead:
	{
		int roaddest = (int)App->scene->MainPlayer.roaddest;
		if (CarParticle1 != NULL)
		{
			CarParticle1->deleteme = true;
			CarParticle2->deleteme = true;
			CarParticle1 = NULL;
			CarParticle2 = NULL;
		}
		switch (roaddest)
		{
		case 0:
		{
			dest.y = posp.y + App->scene->MainPlayer.roadvel;
			destspeed = 0.5 * App->timer->deltatime;
			break;
		}
		case 500:
		{
			dest.y = SCREEN_HEIGHT + 150;
			destspeed = 0.5f * App->timer->deltatime;
			break;
		}
		case 1300:
		{
			dest.y = SCREEN_HEIGHT + 250;
			destspeed = 1 * App->timer->deltatime;
			break;
		}
		}
		dest.x = posp.x;
		posp.NextPoint(dest, destspeed);
		if (posp.x > 715 || posp.x < 155)
			deleteme = true;
		if (posp.y < -230 || posp.y > 830)
			deleteme = true;
		break;
	}
	case collided:
		posp.x = posp.x + colldirx;
		posp.y = posp.y + colldiry;
		if (collidedtime.UpdateTimer())
		{
			carstate = idle;
			collidedtime.Reset();
			colldirx = 0.0f;
			colldiry = 0.0f;
		}
		break;
	default:
		break;
	}
	
	// Collider
	col->rect = rect;
	col->rect.x = posp.x - (col->rect.w / 2);
	col->rect.y = posp.y;
}

void Car::RenderGameObj()
{
	if (maintex != NULL)
	{
		App->renderer->Blit(maintex, posp.x + xoffset, posp.y + yoffset, &rect);
	}
}

void Car::OnCollisionEnter(Collider * ColWith)
{
	if (carstate == idle)
	{
		switch (ColWith->parent->type)
		{
		case gun:
		case oil:
			carstate = dead;
			App->scene->CreateParticle(0, 0, this, false, ModuleScene::boom, false);
			if (type == car)
				App->scene->Points += 200;
			else if (type == mbike)
				App->scene->Points -= 500;
			break;
		case road:
			if (type == car)
			{
				carturn = -carturn;
			}
			else if (type == mbike)
			{
				if (posp.x > ColWith->rect.x)
				{
					bikex += 10;
				}
				else if (posp.x < ColWith->rect.x)
				{
					bikex += -10;
				}
			}
			break;
		case car:
		case mbike:
		case player:
			colldirx = 0;
			colldiry = 0;
			ColDir from;
			from = CollisionDir(ColWith, col);
			if (from != nulldir)
				{
					carstate = collided;
					collidedtime.Start();
					switch (from)
					{
					case updir:
						colldiry = 250;
						break;
					case rightdir:
						colldirx = -250;
						break;
					case leftdir:
						colldirx = 250;
						break;
					case downdir:
						colldiry = -250;
						break;
					default:
						break;
					}
					colldirx = colldirx * App->timer->deltatime;
					colldiry = colldiry * App->timer->deltatime;
				}
			break;
		default:
			break;
		}

	}
	else if (carstate == collided)
	{
		if (ColWith->parent->type == road)
		{
			carstate = dead;
			App->scene->CreateParticle(0, 0, this, false, ModuleScene::boom, false);
			if (type == car)
				App->scene->Points += 400;
			else if (type == mbike)
				App->scene->Points -= 500;
		}
	}
	
	
}
