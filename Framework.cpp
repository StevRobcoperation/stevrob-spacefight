#include "Framework.hpp"


CFramework::CFramework()
{
	renderer = NULL;
	window = NULL;
}

bool CFramework::Init(int screenWidth, int screenHeight, bool screen)
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();

		return false;
	}

	Uint32 flag = 0;

	if (screen == false)
		flag = SDL_WINDOW_SHOWN;
	else if (screen == true)
		flag = SDL_WINDOW_FULLSCREEN_DESKTOP;

	window = SDL_CreateWindow("Spiel",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		flag);

	if (window == NULL)
	{
		cout << "Window konnte nicht gestarted werden" << SDL_GetError() << endl;
		Destroy();

		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL)
	{
		
		cout << "Renderer konnte nicht geladen werden" << SDL_GetError() << endl;

		
		Destroy();
		return false;
		
	}

	keystate = SDL_GetKeyboardState(NULL);
	
	
	return true;

}


void CFramework::Destroy()
{
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);

	}

	if (window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}

void CFramework::Render()
{
	SDL_RenderPresent(renderer);
}

void CFramework::Update()
{
	pTime->Update();
	SDL_RenderPresent(renderer);

}

bool CFramework::Keydown(int Key_ID)
{
	if (keystate[Key_ID])
		return true;
	else
		return false;
}

void CFramework::clear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}