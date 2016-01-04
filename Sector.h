#pragma once
#include <list>
#include "Globals.h"
#include "Application.h"
#include "Player.h"
#include "ModuleScene.h"
#include "Road.h"
#include "ModuleTimer.h"
class Sector : public GameObject
{
public:

	Sector(){}
	~Sector(){}

	std::list<Road> roads;
	bool deleteme = false;
	SectorType type;
	void AddRoadToSector(Road road)
	{
		int final = SectorEnd();
		roads.push_back(road);
		Road* roadp = &roads.back();
		roadp->posp.y = final + roadp->ysize;
		roadp->localpos.y = final + roadp->ysize;
	}
	void CreateColOnSector()
	{
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			it->CreateColForRoad();
		}
	}
	int SectorEnd()
	{
		int suma = 0;
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			suma = suma + it->ysize;
		}
		return suma;
	}

	void RoadUpdate(float vel)
	{
		float offset = vel * App->timer->deltatime;
		posp.y = posp.y + offset;
		/*if ((posy - SectorEnd()) > SECTOR_END)
		{
			deleteme = true;
		}*/
		
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			it->Update();
		}
	}
	void SetParent()
	{
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			it->parent = this;
		}
	}
	void RenderGameObj()
	{
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			App->renderer->Blit(it->texture, it->posp.x, it->posp.y, NULL);
		}
	}
	void DeleteSector()
	{
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); it++)
		{
			it->DelColForRoad();
		}
	}


};

