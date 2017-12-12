#include <iostream>
#include <SDL.h>
#include "Framework.hpp"
#include "Gameplay.hpp"

using namespace std;



int main(int argc, char *args[])
{

	

	

	if (!pFramework->Init(800, 600, false))
	{
		return 0;
	}
	
	CGameplay Game;

	Game.Init();
	
	Game.Run();

	Game.Quit();

	pFramework->Destroy();
	pFramework->Del();


	return 0;
}