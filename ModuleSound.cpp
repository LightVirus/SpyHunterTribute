#include "ModuleSound.h"
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_mixer.h"
#pragma comment( lib, "SDL/libx86/SDL2_mixer.lib" )

ModuleSound::ModuleSound()
{
}


ModuleSound::~ModuleSound()
{
}


bool ModuleSound::Init()
{
	LOG("Init SDL Audio event system");
	bool ret = true;
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error: %s\n", Mix_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleSound::CleanUp()
{
	LOG("Freeing music");

	for (std::list<Mix_Music*>::iterator it = Lmusic.begin(); it != Lmusic.end(); ++it)
		Mix_FreeMusic(*it);
	for (std::list<Mix_Chunk*>::iterator it = Lsoundse.begin(); it != Lsoundse.end(); ++it)
		Mix_FreeChunk(*it);
	Lsoundse.clear();
	Lmusic.clear();
	return true;
}


Mix_Music* const ModuleSound::LoadMusic(const char* path)
{
	Mix_Music *musica = NULL;
	musica = Mix_LoadMUS(path);
	if (musica == NULL)
	{
		printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	Lmusic.push_back(musica);
	return musica;
}

Mix_Chunk* const ModuleSound::LoadSoundE(const char* path)
{
	Mix_Chunk *sonido = NULL;
	sonido = Mix_LoadWAV(path);
	if (sonido == NULL)
	{
		printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	Lsoundse.push_back(sonido);
	return sonido;
}

void const ModuleSound::PlayMusic(Mix_Music* musica)
{
	if (Mix_PlayingMusic() == 0)
	{
		LOG("Musica a tope");
		Mix_PlayMusic(musica, -1);
	}
}

void const ModuleSound::PlaySoundE(Mix_Chunk* sound)
{
	Mix_PlayChannel(-1, sound, 0);
}