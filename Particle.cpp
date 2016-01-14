#include "Particle.h"
#include "Player.h"
#include "Application.h"
#include "ModuleScene.h"

Particle::Particle()
{

}


Particle::~Particle()
{
}

void Particle::CreateParticle(SDL_Texture* Tex, item_type typ, item_type coltyp, float speed, float life, bool loopx)
{
	MainTex = Tex;
	type = typ;
	vel = speed;
	lifetime = life;
	loop = loopx;
	coltype = coltyp;

}

void Particle::CreateParticle(float x, float y, GameObject* parentx, bool colx)
{
	localpos.x = x;
	posp.x = x;
	localpos.y = y;
	posp.y = y;
	parent = parentx;
	if (colx)
	{
		SDL_Rect temp = { 0,0,0,0 };
		col = App->collider->CreateCol(temp, coltype, this);
	}
}


void Particle::Update()
{
	if (lifetime > 0.0f && deadtime.timerstart == 0.0f)
	{
		deadtime.createtimer(lifetime);
	}
	switch (type)
	{


	case gun:
		posp.y += vel;
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

		if (frames.size() > 1)
		{
			if (current_frame < frames.size())
				current_frame += vel * App->timer->deltatime;
			if ((int)current_frame >= frames.size() && loop)
			{
				current_frame = 0.0f;
			}
			else if ((int)current_frame >= frames.size() && !loop)
			{
				vel = 0.0f;
				current_frame = frames.size() - 0.1f;
				deleteme = true;
			}

		}
		break;


	case oil:
		float tempspeed = 0.0f;
		tempspeed = App->scene->MainPlayer.roadvel;
		posp.y += tempspeed * App->timer->deltatime;
		break;
	}


	if (deadtime.timerstart > 0.0f)
		deadtime.UpdateTimer();
	if (deadtime.timerended)
	{
		deleteme = true;
	}
	xoffset = (frames[current_frame].w / 2.0f) * -1;
	if (col != NULL)
	{
		col->rect.w = frames[current_frame].w;
		col->rect.h = frames[current_frame].h;
		col->rect.x = posp.x - (col->rect.w / 2);
		col->rect.y = posp.y + yoffset;
	}

}


void Particle::RenderGameObj()
{
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posp.x + xoffset, posp.y + yoffset, &frames[current_frame]);
	}
}

void Particle::OnCollisionEnter(Collider * ColWith)
{
	if (type == gun)
	{
		if (ColWith->parent->type == car || ColWith->parent->type == mbike)
			deleteme = true;
	}
	
}

