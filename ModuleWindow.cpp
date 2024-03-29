#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"

ModuleWindow::ModuleWindow()
{
}

// Destructor
ModuleWindow::~ModuleWindow()
{
}

// Called before render is available
bool ModuleWindow::Init()
{
	LOG("Init SDL window & surface");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		int width = SCREEN_WIDTH;
		int height = SCREEN_HEIGHT;
		Uint32 flags = SDL_WINDOW_SHOWN;

		if(FULLSCREEN)
		{
			flags |= SDL_WINDOW_FULLSCREEN;
		}
		else if (BORDERLESS)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}
		else if (RESIZABLE)
		{
			flags |= SDL_WINDOW_RESIZABLE;
		}
		else if (FULLSCREEN_DESKTOP)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		// TODO 2: Create options for RESIZABLE, SDL_WINDOW_BORDERLESS, SDL_WINDOW_RESIZABLE,
		// SDL_WINDOW_FULLSCREEN_DESKTOP (same way as with FULLSCREEN)

		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if(window == NULL)
		{
			LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);
		}
	}

	return ret;
}

bool ModuleWindow::Start()
{
	LOG("Start of ModuleWindow working ----");
	return true;
}


// Called before quitting
bool ModuleWindow::CleanUp()
{
	LOG("Destroying SDL window and quitting all SDL systems");

	//Destroy window
	if(window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}

