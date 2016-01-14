
#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleSound.h"
#include "ModuleTimer.h"
#include "ModuleCollider.h"
#include <string>
#include <sstream>
#include <list>

using namespace std;


ModuleScene::ModuleScene()
{
	
}


ModuleScene::~ModuleScene()
{
}


bool ModuleScene::Start()
{
	//Load Resources
	mainsprites = App->textures->Load("Game/Images/MainSprites.png");
	mainui = App->textures->Load("Game/Images/UI.png");
	
	
	RectaMedBigTEX = App->textures->Load("Game/Images/road/RectaMedBig.png");
	CambioBigEstrTEX = App->textures->Load("Game/Images/road/CambioBigEstr.png");
	RectaMedEstrTEX = App->textures->Load("Game/Images/road/RectaMedEstr.png");
	RectaDerEstrTEX = App->textures->Load("Game/Images/road/RectaDerEstr.png");
	RectaIzqEstrTEX = App->textures->Load("Game/Images/road/RectaIzqEstr.png");
	CurvaDerMedEstrTEX = App->textures->Load("Game/Images/road/CurvaDerMedEstr.png");
	CurvaIzqMedEstrTEX = App->textures->Load("Game/Images/road/CurvaIzqMedEstr.png");
	CurvaMedDerEstrTEX = App->textures->Load("Game/Images/road/CurvaMedDerEstr.png");
	CurvaMedIzqEstrTEX = App->textures->Load("Game/Images/road/CurvaMedIzqEstr.png");
	godTEX = App->textures->Load("Game/Images/godsprite.png");
	

	
	music1 = App->sound->LoadMusic("Game/Sound/maintheme.ogg");
	deadmusic = App->sound->LoadMusic("Game/Sound/deadmusic.ogg");
	boomSE = App->sound->LoadSoundE("Game/Sound/boomSE.ogg");
	gunSE = App->sound->LoadSoundE("Game/Sound/gunSE.ogg");
	roadoutSE = App->sound->LoadSoundE("Game/Sound/roadoutSE.ogg");

	

	MainFont32 = App->textures->LoadFont("Game/mainfont.ttf", 32);
	MainFont22 = App->textures->LoadFont("Game/mainfont.ttf", 22);
	Mix_VolumeMusic(50);
	App->sound->PlayMusic(music1,0);
	
	//Set Roads
	RectaMedBig.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaMedBig.SetSize(RectaMedBigTEX);
	RectaMedBig.AddRectToRoad(0, 0, 83, 515);
	RectaMedBig.AddRectToRoad(397, 0, 83, 515);

	CambioBigEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CambioBigEstr.SetSize(CambioBigEstrTEX);
	CambioBigEstr.AddRectToRoad(0,0,155,138);
	CambioBigEstr.AddRectToRoad(325,0,155,138);
	CambioBigEstr.AddRectToRoad(0,138,149,64);
	CambioBigEstr.AddRectToRoad(331,138,149,64);
	CambioBigEstr.AddRectToRoad(0,202,145,64);
	CambioBigEstr.AddRectToRoad(335,202,145,64);
	CambioBigEstr.AddRectToRoad(0, 266, 141, 64);
	CambioBigEstr.AddRectToRoad(339,266,141,64);
	CambioBigEstr.AddRectToRoad(0,330,137,64);
	CambioBigEstr.AddRectToRoad(343,330,137,64);
	CambioBigEstr.AddRectToRoad(0,394,131,64);
	CambioBigEstr.AddRectToRoad(349,394,131,64);
	CambioBigEstr.AddRectToRoad(0,458,123,206);
	CambioBigEstr.AddRectToRoad(357,458,123,206);
	CambioBigEstr.AddRectToRoad(0,664,116,126);
	CambioBigEstr.AddRectToRoad(364,664,116,126);
	CambioBigEstr.AddRectToRoad(0,790,110,66);
	CambioBigEstr.AddRectToRoad(370, 790, 110, 66);
	CambioBigEstr.AddRectToRoad(0,856,106,66);
	CambioBigEstr.AddRectToRoad(374,856,106,66);
	CambioBigEstr.AddRectToRoad(0,920,99,60);
	CambioBigEstr.AddRectToRoad(381,920,99,60);

	RectaMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaMedEstr.SetSize(RectaMedEstrTEX);
	RectaMedEstr.AddRectToRoad(0, 0, 152, 515);
	RectaMedEstr.AddRectToRoad(328, 0, 152, 515);

	RectaDerEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaDerEstr.SetSize(RectaDerEstrTEX);
	RectaDerEstr.AddRectToRoad(0, 0, 248, 515);
	RectaDerEstr.AddRectToRoad(424, 0, 56, 515);

	RectaIzqEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaIzqEstr.SetSize(RectaIzqEstrTEX);
	RectaIzqEstr.AddRectToRoad(0, 0, 55, 515);
	RectaIzqEstr.AddRectToRoad(232,0,248,515);

	CurvaDerMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CurvaDerMedEstr.SetSize(CurvaDerMedEstrTEX);
	CurvaDerMedEstr.AddRectToRoad(0, 0, 160, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 100, 180, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 200, 200, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 300, 220, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 400, 240, 110);
	CurvaDerMedEstr.AddRectToRoad(330, 0, 150, 100);
	CurvaDerMedEstr.AddRectToRoad(350, 100, 130, 100);
	CurvaDerMedEstr.AddRectToRoad(370, 200, 110, 100);
	CurvaDerMedEstr.AddRectToRoad(390, 300, 90, 100);
	CurvaDerMedEstr.AddRectToRoad(410, 400, 70, 110);

	CurvaIzqMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CurvaIzqMedEstr.SetSize(CurvaIzqMedEstrTEX);
	CurvaIzqMedEstr.AddRectToRoad(0, 0, 150, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 100, 130, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 200, 110, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 300, 90, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 400, 70, 110);
	CurvaIzqMedEstr.AddRectToRoad(320, 0, 160, 100);
	CurvaIzqMedEstr.AddRectToRoad(300, 100, 180, 100);
	CurvaIzqMedEstr.AddRectToRoad(280, 200, 200, 100);
	CurvaIzqMedEstr.AddRectToRoad(260, 300, 220, 100);
	CurvaIzqMedEstr.AddRectToRoad(240, 400, 240, 110);

	CurvaMedDerEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CurvaMedDerEstr.SetSize(CurvaMedDerEstrTEX);
	CurvaMedDerEstr.AddRectToRoad(0, 0, 250, 100);
	CurvaMedDerEstr.AddRectToRoad(0, 100, 230, 100);
	CurvaMedDerEstr.AddRectToRoad(0, 200, 210, 100);
	CurvaMedDerEstr.AddRectToRoad(0, 300, 190, 100);
	CurvaMedDerEstr.AddRectToRoad(0, 400, 170, 110);
	CurvaMedDerEstr.AddRectToRoad(410, 0, 70, 100);
	CurvaMedDerEstr.AddRectToRoad(390, 100, 90, 100);
	CurvaMedDerEstr.AddRectToRoad(370, 200, 110, 100);
	CurvaMedDerEstr.AddRectToRoad(350, 300, 130, 100);
	CurvaMedDerEstr.AddRectToRoad(330, 400, 150, 110);

	CurvaMedIzqEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CurvaMedIzqEstr.SetSize(CurvaMedIzqEstrTEX);
	CurvaMedIzqEstr.AddRectToRoad(0, 0, 70, 100);
	CurvaMedIzqEstr.AddRectToRoad(0, 100, 90, 100);
	CurvaMedIzqEstr.AddRectToRoad(0, 200, 110, 100);
	CurvaMedIzqEstr.AddRectToRoad(0, 300, 130, 100);
	CurvaMedIzqEstr.AddRectToRoad(0, 400, 150, 110);
	CurvaMedIzqEstr.AddRectToRoad(230, 0, 250, 100);
	CurvaMedIzqEstr.AddRectToRoad(250, 100, 230, 100);
	CurvaMedIzqEstr.AddRectToRoad(270, 200, 210, 100);
	CurvaMedIzqEstr.AddRectToRoad(290, 300, 190, 100);
	CurvaMedIzqEstr.AddRectToRoad(310, 400, 170, 110);


	//Set Sectors
	SECTRectaBig.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTRectaBig.type = big;
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	
	SECTCambioBigEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCambioBigEstr.type = estr;
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(CambioBigEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);

	SECTRectaMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTRectaMedEstr.type = estr;
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);
	SECTRectaMedEstr.AddRoadToSector(RectaMedEstr);

	SECTCurvaMedDerEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCurvaMedDerEstr.type = estrder;
	SECTCurvaMedDerEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(CurvaMedDerEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaMedDerEstr.AddRoadToSector(RectaDerEstr);

	SECTRectaDerEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTRectaDerEstr.type = estrder;
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);
	SECTRectaDerEstr.AddRoadToSector(RectaDerEstr);

	SECTCurvaDerMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCurvaDerMedEstr.type = estr;
	SECTCurvaDerMedEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaDerEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(CurvaDerMedEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaDerMedEstr.AddRoadToSector(RectaMedEstr);

	SECTCurvaMedIzqEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCurvaMedIzqEstr.type = estrizq;
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(CurvaMedIzqEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaMedIzqEstr.AddRoadToSector(RectaIzqEstr);

	SECTRectaIzqEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTRectaIzqEstr.type = estrizq;
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);
	SECTRectaIzqEstr.AddRoadToSector(RectaIzqEstr);

	SECTCurvaIzqMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCurvaIzqMedEstr.type = estr;
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaIzqEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(CurvaIzqMedEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaMedEstr);
	SECTCurvaIzqMedEstr.AddRoadToSector(RectaMedEstr);

	
	SECTTEST.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	
	

	//Player
	MainPlayer.SetGameObj(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 180, -15, 0, true, player, false);

	MainPlayer.SetPlayer(App->collider->CreateCol(MainPlayer.colidle, player, &MainPlayer), mainsprites);

	spawntimer.endtime = SPAWN_TIME;
	
	stringstream godmodetext;
	godmodetext.str("");
	godmodetext << "GOD MODE";
	SDL_Color White = { 255, 255, 255 };
	godtext = App->textures->Font2Texture(MainFont32, godmodetext.str().c_str(), White);
	
	
	
	
	SDL_SetRenderDrawBlendMode(App->renderer->renderer, SDL_BLENDMODE_BLEND);
	return true;


}

bool ModuleScene::CleanUp()
{
	
	for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end();)
	{
		itA = SectorsList.erase(itA);
	}
	SectorsList.clear();
	for (list<Particle*>::iterator itA = PAList.begin(); itA != PAList.end();)
	{
			if ((*itA)->col != NULL)
			{
				(*itA)->col->deleteme = true;
				(*itA)->col->parent = NULL;
			}
			RELEASE (*itA);
			itA = PAList.erase(itA);
	}
	PAList.clear();
	for (list<Car*>::iterator itA = CarList.begin(); itA != CarList.end();)
	{
			RELEASE(*itA);
			itA = CarList.erase(itA);
	}
	CarList.clear();
	return true;
}


update_status ModuleScene::Update()
{
	if (fristtime)
	{
		SectorsList.push_back(SECTRectaBig);
		SectorsList.back().SetParent();
		SectorsList.back().posp.y = SCREEN_HEIGHT;
		
		int nexty = (SectorsList.back().posp.y - SectorsList.back().SectorEnd());
		SectorsList.push_back(SECTRectaBig);
		SectorsList.back().SetParent();
		SectorsList.back().posp.y = nexty;

		for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
		{
			itA->CreateColOnSector();
		}
		MainPlayer.firetimer.endtime = 50;
		MainPlayer.oiltimer.endtime = 30;
		spawntimer.Start();
		
	}
	// Create Sectors and delete them
	if (SectorsList.front().posp.y > (SectorsList.front().SectorEnd() + 1300))
	{
		
		SectorsList.front().DeleteSector();
		list<Sector>::iterator it = SectorsList.begin();
		it = SectorsList.erase(it);
		
		Sector* nextone = SetNextSector(&SectorsList.back());
		int nexty = (SectorsList.back().posp.y - SectorsList.back().SectorEnd());
		SectorsList.push_back(*nextone);
		SectorsList.back().posp.y = nexty;
		for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
		{
			itA->SetParent();
		}
		SectorsList.back().CreateColOnSector();
		

	}
	// Create and delete cars
	for (list<Car*>::iterator itA = CarList.begin(); itA != CarList.end();)
	{
		if ((*itA)->deleteme)
		{
			RELEASE(*itA);
			itA = CarList.erase(itA);
			LOG("Borrado car");
		}
		else
			++itA;
	}
	if (spawntimer.UpdateTimer())
	{
		spawntimer.Start();
		if (CarList.size() < MAX_CARS)
		{

			int random = rand() % 2 + 0;
			if (random == 1)
			{
				srand(SDL_GetTicks());
				int random2 = rand() % 1 + 0;
				if (random == 1)
				{
					srand(SDL_GetTicks());
					int random3 = rand() % 500 + 280;
					CarList.push_back(new Car(random3, -200, true, mainsprites, car));
				}

				else
				{
					srand(SDL_GetTicks());
					int random4 = rand() % 500 + 280;
					CarList.push_back(new Car(random4, 800, true, mainsprites, car));
				}

				LOG("Añadido enemigo");
			}
			else if (random == 0)
			{
				srand(SDL_GetTicks());
				int random2 = rand() % 1 + 1;
				if (random == 1)
					CarList.push_back(new Car(SCREEN_WIDTH / 2, -200, true, mainsprites, mbike));
				else
					CarList.push_back(new Car(SCREEN_WIDTH / 2, 800, true, mainsprites, mbike));
				LOG("Añadido civil");
			}

		}
	}
	
	



	// Road
	for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
	{
		itA->RoadUpdate(MainPlayer.roadvel);
	}
	
	//Cars
	for (list<Car*>::iterator itA = CarList.begin(); itA != CarList.end(); ++itA)
	{
		(*itA)->Update();
	}
	
	// Player
	MainPlayer.Update();
	
	//Particles
	for (list<Particle*>::iterator itA = PAList.begin(); itA != PAList.end(); ++itA)
	{
		(*itA)->Update();
	}
	
	
	// RenderGO
	for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
	{
		itA->RenderGameObj();
	}

	for (list<Particle*>::iterator itA = PAList.begin(); itA != PAList.end(); ++itA)
	{
		if ((*itA)->earlyrender)
			(*itA)->RenderGameObj();
	}
	for (list<Car*>::iterator itA = CarList.begin(); itA != CarList.end(); ++itA)
	{
		(*itA)->RenderGameObj();
	}
	MainPlayer.RenderGameObj();
	
	for (list<Particle*>::iterator itA = PAList.begin(); itA != PAList.end(); ++itA)
	{
		if(!(*itA)->earlyrender && !(*itA)->lastrender)
			(*itA)->RenderGameObj();
	}
	
	for (list<Particle*>::iterator itA = PAList.begin(); itA != PAList.end();)
	{
		if ((*itA)->deleteme)
		{
			if ((*itA)->col != NULL)
			{
				(*itA)->col->deleteme = true;
				(*itA)->col->parent = NULL;
			}
			RELEASE (*itA);
			itA = PAList.erase(itA);

		}
		else
			itA++;
	}
	
	// Render Colliders
	if(MainPlayer.RenderCol)
		App->collider->RenderCol();

	// Render UI
	App->renderer->Blit(mainui, 0, 0, NULL);

	for (list<Particle*>::iterator itA = PAList.begin(); itA != PAList.end(); ++itA)
	{
		if ((*itA)->lastrender)
			(*itA)->RenderGameObj();
	}
	
	//God mode text
	if(MainPlayer.godmode)
		App->renderer->Blit(godtext, SCREEN_WIDTH /2 - 85, 20, NULL);
	
	// FPS
	stringstream timeText;
	timeText.str("");
	timeText << "FPS: " << App->timer->finalfps;
	SDL_Color White = { 255, 255, 255 };
	SDL_Texture* fpstexture = App->textures->Font2Texture(MainFont22, timeText.str().c_str(), White);
	App->renderer->Blit(fpstexture, 6, SCREEN_HEIGHT - 25, NULL);
	SDL_DestroyTexture(fpstexture);
	timeText.clear();
	
	// Points
	if(MainPlayer.turbo && !MainPlayer.deadbool)
		Points += 150 * App->timer->deltatime;
	else if (!MainPlayer.deadbool)
		Points += 125 * App->timer->deltatime;
	
	
	stringstream pText;
	pText.str("");
	pText << "Points: " << Points;
	SDL_Texture* pTexture = App->textures->Font2Texture(MainFont22, pText.str().c_str(), White);
	int tempsize = 0;
	SDL_QueryTexture(pTexture, NULL, NULL, &tempsize, NULL);
	App->renderer->Blit(pTexture, (SCREEN_WIDTH / 2) - (tempsize / 2), 50, NULL);
	SDL_DestroyTexture(pTexture);
	pText.clear();
	
	if (fristtime)
		fristtime = false;
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	MainPlayer.PostUpdate();
	return UPDATE_CONTINUE;
}


Sector * ModuleScene::SetNextSector(Sector* last)
{
	Sector* next = NULL;
	srand(SDL_GetTicks());
	int random = rand() % 10 + 1;
	switch (last->type)
	{
	case big:
		if (random > 0 && random <= 3)
			return next = &SECTRectaBig;
		if (random > 3 && random <= 10)
			return next = &SECTCambioBigEstr;
	case estr:
		if (random > 0 && random <= 3)
			return next = &SECTRectaMedEstr;
		if (random > 3 && random <= 6)
			return next = &SECTCurvaMedDerEstr;
		if (random > 6 && random <= 10)
			return next = &SECTCurvaMedIzqEstr;
	case estrder:
		if (random > 0 && random <= 3)
			return next = &SECTRectaDerEstr;
		if (random > 3 && random <= 10)
			return next = &SECTCurvaDerMedEstr;
	case estrizq:
		if (random > 0 && random <= 3)
			return next = &SECTRectaIzqEstr;
		if (random > 3 && random <= 10)
			return next = &SECTCurvaIzqMedEstr;
	}
	return nullptr;
}

Particle * ModuleScene::CreateParticle(float x, float y, GameObject * parentx, bool col, P_Type type, bool gun2bool)
{
	SDL_Rect temp;
	PAList.push_back(P1 = new Particle());
	switch (type)
	{
	case gun1:
		P1->CreateParticle(mainsprites, anim, gun, 20.0f, 0, true);
		P1->CreateParticle(x, y, parentx, col);
		P1->frames.push_back(temp = { 212,230,14,32 });
		P1->frames.push_back(temp = { 122,222,14,32 });
		P1->yoffset = -30;
		break;
	case gun2:
		P1->CreateParticle(mainsprites, gun, gun, -10, 0.5, true);
		P1->CreateParticle(x, y, parentx, col);
		P1->frames.push_back(temp = { 149,230,10,22 });
		P1->frames.push_back(temp = { 189,238,10,22 });
		P1->current_frame = gun2bool;
		App->sound->PlaySoundE(gunSE);
		break;
	case oil1:
		P1->CreateParticle(mainsprites, anim, null, 0.0f, 0, false);
		P1->CreateParticle(x, y, parentx, col);
		P1->frames.push_back(temp = { 3,230,32,25 });
		break;
	case oil2:
		P1->CreateParticle(mainsprites, oil, oil, 10, 0.5, false);
		P1->CreateParticle(x, y, parentx, col);
		P1->frames.push_back(temp = { 83,223,32,32 });
		P1->earlyrender = true;
		break;
	case sharp:
		P1->CreateParticle(mainsprites, anim, enemyweapon, 0, 0, false);
		P1->CreateParticle(x, y, parentx, col);
		if(gun2bool)
			P1->frames.push_back(temp = { 245,235,14,27 });
		else
			P1->frames.push_back(temp = { 261,235,14,27 });
		P1->earlyrender = true;
		break;
	case boom:
		P1->CreateParticle(mainsprites, anim, null, 10.0f, 0, false);
		P1->CreateParticle(x, y, parentx, col);
		P1->frames.push_back(temp = { 184,275,37,34 });
		P1->frames.push_back(temp = { 225,275,37,34 });
		P1->frames.push_back(temp = { 265,275,37,34 });
		P1->frames.push_back(temp = { 305,275,37,34 });
		P1->frames.push_back(temp = { 343,275,37,34 });
		App->sound->PlaySoundE(boomSE);
		break;
	case god:
		P1->CreateParticle(godTEX, anim, null, 20.0f, 0, true);
		P1->CreateParticle(x, y, parentx, col);
		P1->frames.push_back(temp = { 0, 0, 141, 200 });
		P1->frames.push_back(temp = { 142, 0, 141, 200 });
		P1->frames.push_back(temp = { 284, 0, 141, 200 });
		P1->frames.push_back(temp = { 0, 201, 141, 200 });
		P1->frames.push_back(temp = { 142, 201, 141, 200 });
		P1->frames.push_back(temp = { 284, 201, 141, 200 });
		P1->frames.push_back(temp = { 426, 0, 141, 200 });
		P1->frames.push_back(temp = { 568, 0 ,141, 200 });
		P1->frames.push_back(temp = { 426, 201, 141, 200 });
		P1->frames.push_back(temp = { 710, 0, 141, 200 });
		P1->frames.push_back(temp = { 568, 201, 141, 200 });
		P1->frames.push_back(temp = { 852, 0, 141, 200 });
		P1->frames.push_back(temp = { 710, 201, 141, 200 });
		P1->frames.push_back(temp = { 852, 201, 141, 200 });
		P1->frames.push_back(temp = { 0, 402, 141, 200 });
		P1->frames.push_back(temp = { 142, 402, 141, 200 });
		P1->frames.push_back(temp = { 0, 603, 141, 200 });
		P1->frames.push_back(temp = { 284, 402, 141, 200 });
		P1->frames.push_back(temp = { 142, 603, 141, 200 });
		P1->frames.push_back(temp = { 426, 402, 141, 200 });
		P1->frames.push_back(temp = { 284, 603, 141, 200 });
		P1->frames.push_back(temp = { 568, 402, 141, 200 });
		P1->frames.push_back(temp = { 426, 603, 141, 200 });
		P1->frames.push_back(temp = { 710, 402, 141, 200 });
		P1->lastrender = true;
		break;
	}
	

	return P1;
}

