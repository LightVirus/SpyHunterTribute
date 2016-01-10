#pragma once

#include "Application.h"
#include "GameObject.h"
#include "Road.h"
#include "Sector.h"
#include "Particle.h"
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_mixer.h"
#include "SDL/include/SDL_image.h"
#include "SDL/include/SDL_ttf.h"
#include <list>

class Player;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();
	
	Player MainPlayer;
	
	enum P_Type
	{
		gun1,
		gun2,
		oil1,
		oil2,
		oil3,
		boom,
		sharp
	};
	
	bool fristtime;
	bool Start();
	bool CleanUp();
	update_status Update();
	update_status PostUpdate();
	
	Sector* SetNextSector(Sector* last);
	Particle* CreateParticle(float x, float y, GameObject * parentx, bool col, P_Type type, bool gun2bool);

	
private:
	list<Sector> SectorsList;
	//Textures
	SDL_Texture* mainsprites = NULL;
	SDL_Texture* RectaMedBigTEX = NULL;
	SDL_Texture* RectaMedEstrTEX = NULL;
	SDL_Texture* CambioBigEstrTEX = NULL;
	SDL_Texture* RectaDerEstrTEX = NULL;
	SDL_Texture* RectaIzqEstrTEX = NULL;
	SDL_Texture* CurvaDerMedEstrTEX = NULL;
	SDL_Texture* CurvaIzqMedEstrTEX = NULL;
	SDL_Texture* CurvaMedDerEstrTEX = NULL;
	SDL_Texture* CurvaMedIzqEstrTEX = NULL;
	SDL_Texture* mainui = NULL;
	TTF_Font* MainFont = NULL;

	//Music
	Mix_Music* music1 = NULL;

	//Sounds
	Mix_Chunk* effect1 = NULL;
	Mix_Chunk* effect2 = NULL;

	//Road
	Road RectaMedBig;
	Road RectaMedEstr;
	Road CambioBigEstr;
	Road RectaDerEstr;
	Road RectaIzqEstr;
	Road CurvaDerMedEstr;
	Road CurvaIzqMedEstr;
	Road CurvaMedDerEstr;
	Road CurvaMedIzqEstr;

	//Sector
	Sector SECTRectaBig;
	Sector SECTCambioBigEstr;
	Sector SECTRectaMedEstr;
	Sector SECTCurvaMedDerEstr;
	Sector SECTRectaDerEstr;
	Sector SECTCurvaDerMedEstr;
	Sector SECTCurvaMedIzqEstr;
	Sector SECTRectaIzqEstr;
	Sector SECTCurvaIzqMedEstr;

	Sector SECTTEST;

	//Particles
	Particle* P1;

	
	//GameObjects
	list<Particle*> PAList;
	


	float x = 0.0f;
	float y = 0.0f;

	float xdir = 50.0f;
	float ydir = 50.0f;

	

};

