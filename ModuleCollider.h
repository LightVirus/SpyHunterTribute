#pragma once
#include "Module.h"
#include "Globals.h"
#include "GameObject.h"
#include "SDL/include/SDL.h"
#include "Collider.h"

#include <list>
class ModuleCollider :
	public Module
{
public:
	ModuleCollider();
	~ModuleCollider();

	std::list<Collider> Colliders;

	void CheckAllCol();
	


	

	Collider* CreateCol(SDL_Rect box, item_type type, GameObject * parent);
	Collider* DelCol(Collider* col);
	void DelMarkedCol();
	void RenderCol();
	//bool Collision(SDL_Rect a, SDL_Rect b);
	void UpdateCol();
	bool CleanUp();
	update_status Update();
};

