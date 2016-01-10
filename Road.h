#pragma once
#include "Globals.h"
#include "Application.h"
#include "ModuleCollider.h"
#include "GameObject.h"
#include "Collider.h"
#include "Point.h"
#include <list>
#include "SDL/include/SDL.h"

using namespace std;


class Road : public GameObject
{
public:
	Road() {}
	~Road() {}

	SDL_Texture* texture = NULL;
	list<SDL_Rect> cuadrados;
	list<Collider*> colliders;
	int ysize;

	void SetSize(SDL_Texture* text)
	{
		texture = text;
		SDL_QueryTexture(texture, NULL, NULL, NULL, &ysize);
	}
		
	
	void AddRectToRoad(SDL_Rect rect)
	{
		cuadrados.push_back(rect);
	}
	void AddRectToRoad(int x, int y, int w, int h)
	{
		SDL_Rect temp = { x,y,w,h };
		cuadrados.push_back(temp);
	}

	void CreateColForRoad()
	{
		for (list<SDL_Rect>::iterator itA = cuadrados.begin(); itA != cuadrados.end(); ++itA)
		{
			//SDL_Rect temp = { itA->x,itA->y,itA->w,itA->h };
			colliders.push_back(App->collider->CreateCol((*itA), road, this));
		}
	}

	void DelColForRoad()
	{
		for (list<Collider*>::iterator itA = colliders.begin(); itA != colliders.end(); ++itA)
		{
			App->collider->DelCol(*itA);
		}
		colliders.clear();
	}

	void Update()
	{
		if (parent != NULL)
		{
			posp.y = parent->posp.y - localpos.y;
		}
		
		
		//Update Colliders
		for (list<Collider*>::iterator itA = colliders.begin(); itA != colliders.end(); ++itA)
		{
			(*itA)->rect.x = int(posp.x + (*itA)->localrect.x);
			(*itA)->rect.y = int(posp.y + (*itA)->localrect.y);
		}
	}

};

