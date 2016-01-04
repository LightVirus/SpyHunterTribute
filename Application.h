#pragma once

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleScene;
class ModuleSound;
class ModuleTimer;
class ModuleCollider;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();



public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleScene* scene;
	ModuleSound* sound;
	ModuleTimer* timer;
	ModuleCollider* collider;

private:

	std::list<Module*> modules;

};

extern Application* App;