#pragma once
#include<list>
#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_ttf.h"

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* const Load(const char* path);
	TTF_Font* const LoadFont(const char* path, int size);
	SDL_Texture* Font2Texture(TTF_Font* font, const char* path, SDL_Color color);
private:
	std::list<SDL_Texture*> textures;
	std::list<TTF_Font*> fonts;
};