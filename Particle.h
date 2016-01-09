#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "Application.h"
#include "ModuleRender.h"
#include "Globals.h"
#include "Timer.h"
#include "SDL/include/SDL.h"
#include "Point.h"
class Particle :
	public GameObject
{
private:
	float current_frame = 0.0f;
public:
	Particle(){}
	~Particle(){}
	
	Collider* col = NULL;
	bool loop = false;
	float vel = 0.0f;
	std::vector<SDL_Rect> frames;
	Particle* CreateParticle(float x, float y, float offx, float offy, item_type typ, float speed, GameObject* parentx, Collider* colx)
	{
		localpos.x = x;
		localpos.y = y;
		xoffset = offx;
		yoffset = offy;
		type = typ;
		vel = speed;
		parent = parentx;
		col = colx;
	}
	void Update()
	{
		switch (type)
		{
		case gun:

			break;
		case anim:
			if (parent != NULL)
			{
				posp.x = parent->posp.x + localpos.x;
				posp.y = parent->posp.y + localpos.y;
			}
			else
			{
				posp.x = localpos.x;
				posp.y = localpos.y;
			}
			
			if (frames.size > 1)
			{
				if(current_frame < frames.size())
					current_frame += vel;
				else if (current_frame >= frames.size() && loop)
					current_frame = 0.0f;
			}
			break;
		case oil:
			break;
		}
		
		if (col != NULL)
		{
			col->rect.w = frames[current_frame].w;
			col->rect.h = frames[current_frame].h;
			col->rect.x = posp.x - (col->rect.w / 2);
			col->rect.y = posp.y;
		}
	}

};

