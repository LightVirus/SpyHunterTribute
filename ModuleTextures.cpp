#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_ttf.h"
#pragma comment( lib, "SDL/libx86/SDL2_ttf.lib" )
#include "SDL/include/SDL_image.h"
#pragma comment( lib, "SDL/libx86/SDL2_image.lib" )

using namespace std;

ModuleTextures::ModuleTextures()
{
}

// Destructor
ModuleTextures::~ModuleTextures()
{
	IMG_Quit();
	TTF_Quit();
}

// Called before render is available
bool ModuleTextures::Init()
{
	LOG("Init Image library");
	bool ret = true;

	// load support for the PNG image format
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	if((init & flags) != flags)
	{
		LOG("Could not initialize Image lib. IMG_Init: %s", IMG_GetError());
		ret = false;
	}
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		ret = false;
	}

	return ret;
}

// Called before quitting
bool ModuleTextures::CleanUp()
{
	LOG("Freeing textures and Image library");

	for(list<SDL_Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
		SDL_DestroyTexture(*it);

	textures.clear();
	return true;
}

// Load new texture from file path
SDL_Texture* const ModuleTextures::Load(const char* path)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(path);

	if(surface == NULL)
	{
		LOG("Could not load surface with path: %s. IMG_Load: %s", path, IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(App->renderer->renderer, surface);

		if(texture == NULL)
		{
			LOG("Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			textures.push_back(texture);
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

TTF_Font* const ModuleTextures::LoadFont(const char* path, int size)
{
	
	TTF_Font* font = TTF_OpenFont(path, size);
	if (font == NULL)
	{
		LOG("Could not load font with path: %s. TTF_Load: %s", path, TTF_GetError());
	}
	fonts.push_back(font);
	return font;
}

SDL_Texture* ModuleTextures::Font2Texture(TTF_Font* font, const char* text, SDL_Color color)
{
	if (font != NULL)
	{
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, color);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(App->renderer->renderer, surfaceMessage);
		return Message;
	}
	else
	{
		LOG("Error on reading a previusly loaded font");
	}
	
	
}