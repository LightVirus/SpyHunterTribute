#pragma once
#include "Module.h"
#include "Globals.h"


struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, float x, float y, SDL_Rect* section);
	void BlitCollider(SDL_Color color, SDL_Rect rect);

public:
	SDL_Renderer* renderer = NULL;
	
};