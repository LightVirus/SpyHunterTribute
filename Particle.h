#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "Application.h"
#include "ModuleRender.h"
#include "Globals.h"
#include "Timer.h"
#include "ModuleTimer.h"
#include "ModuleCollider.h"
#include "SDL/include/SDL.h"
#include "Point.h"
#include <vector>

class ModuleScene;

class Particle :
	public GameObject
{
private:
	
public:

	Particle();
	~Particle();
	SDL_Texture* MainTex;
	item_type coltype;
	Timer deadtime;
	float lifetime;
	Collider* col = NULL;
	bool loop = false;
	bool earlyrender = false;
	bool lastrender = false;
	float vel = 0.0f;
	float current_frame = 0.0f;
	std::vector<SDL_Rect> frames;
	
	void CreateParticle(SDL_Texture* Tex, item_type typ, item_type coltyp, float speed, float life, bool loopx);
	void CreateParticle(float x, float y, GameObject* parentx, bool colx);
	void Update();
	void RenderGameObj();
	void OnCollisionEnter(Collider* ColWith);
	

	
};

