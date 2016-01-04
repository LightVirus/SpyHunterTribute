#pragma once
#include <list>
#include "Globals.h"
#include "Module.h"
#include "Application.h"
#include "SDL/include/SDL_mixer.h"

class Application;

class ModuleSound : public Module
{
public:
	ModuleSound();
	~ModuleSound();

	bool Init();
	bool CleanUp();
	Mix_Music* const LoadMusic(const char* path);
	Mix_Chunk* const LoadSoundE(const char* path);
	void const PlayMusic(Mix_Music* musica);
	void const PlaySoundE(Mix_Chunk* sound);
	




private:
	std::list<Mix_Music*> Lmusic;
	std::list<Mix_Chunk*> Lsoundse;
};

