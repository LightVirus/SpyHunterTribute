#include "Car.h"
#include "ModuleScene.h"
#include "Player.h"


Car::Car(float x, float y, bool colx, SDL_Texture* maintexx, item_type typex)
{
	posp.x = x;
	posp.y = y;
	type = typex;
	if (colx)
		col = App->collider->CreateCol(rect, car, this);
	if (type == car)
	{
		rect = { 192,182,25,41 };
		colrect = { 0,0,25,41 };
	}
	else if (type == mbike)
	{
		rect = { 340,180,23,32 };
		colrect = { 0,0,19,32 };
		xoffset = -5;
	}
		

		
}


Car::~Car()
{
	col->deleteme = true;
	col = NULL;
}

void Car::Update()
{
	//Calculate Y
	int roaddest = (int)App->scene->MainPlayer.roaddest;
	switch (roaddest)
	{
	case 0:
	{
		dest.y = -100;
		destspeed = 2;
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
			srand(time(NULL));
			int random = rand() % 575 + 76;
			dest.y = random;
		}
		destspeed = 0.5f;
		break;
	}
	case 1300:
	{
		dest.y = SCREEN_HEIGHT + 100;
		destspeed = 2;
		break;
	}
	
	default:
		break;
	}

	//Calculate Y

	posp.NextPoint(dest, destspeed);
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

void Car::OnCollisionEnter(GameObject * ColWith)
{
}
