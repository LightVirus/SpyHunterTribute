#pragma once
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModuleSound.h"
#include "ModuleTimer.h"
#include "ModuleCollider.h"


using namespace std;

Application::Application()
{
	// Order matters: they will Init/start/update in this order
	modules.push_back(window = new ModuleWindow());
	modules.push_back(renderer = new ModuleRender());
	modules.push_back(textures = new ModuleTextures());
	modules.push_back(input = new ModuleInput());
	modules.push_back(scene = new ModuleScene());
	modules.push_back(sound = new ModuleSound());
	modules.push_back(timer = new ModuleTimer());
	modules.push_back(collider = new ModuleCollider());
	


	// TODO 7: Create a new "scene" module that loads a texture and draws it on the screen

	// Homework: Create a new module to handle music and sound effects
}

Application::~Application()
{
	// TODO 6: Free module memory and check the result in Dr. Memory
	delete window;
	delete renderer;
	delete textures;
	delete input;
	delete scene;
	delete sound;
	delete timer;
	delete collider;
}

bool Application::Init()
{
	bool ret = true;

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Init();

	return ret;
}

bool Application::Start()
{
	bool ret = true;

	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Start();

	return ret;
}
// TODO 4: We need to have three updates, add them: PreUpdate Update PostUpdate

update_status Application::PreUpdate()
{
	update_status ret = UPDATE_CONTINUE;
	
	App->timer->StartLoop();
	App->timer->CalculateFPS();

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PreUpdate();

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->Update();

	return ret;
}

update_status Application::PostUpdate()
{
	update_status ret = UPDATE_CONTINUE;

	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PostUpdate();
	
	if (FPSLOCK && !VSYNC)
		App->timer->FPSMax();
	
	App->timer->EndLoop();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(list<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend() && ret; ++it)
		ret = (*it)->CleanUp();

	return ret;
}
