#include "Gameplay.hpp"
#include <SDL.h>


CGameplay::CGameplay()
{
	m_pBackground = NULL;
	m_pPlayer = NULL;
	
}

void CGameplay::Init()
{
	m_pPlayer = new CPlayer;
	m_pPlayer->Init("Data/Player.bmp", "Data/Laser.bmp",64, 64, 64, 64, 11, 0);
	m_pPlayer->setstartpos();
  
	m_pBackground = new CSprite;
	m_pBackground->load("Data/Background.bmp");

	m_pEnemy = new CEnemy;
	m_pEnemy->Init("Data/Player.bmp", "Data/Laser.bmp", 64, 64, 64, 64, 11, 0);
	m_pEnemy->setstartpos(700.0f, 268.0f);

	


	
	m_GameRun = true; 
	
}

void CGameplay::Quit()
{
	if (m_pPlayer != NULL)
	{
		m_pPlayer->Destroy();
		delete (m_pPlayer);
		m_pPlayer = NULL;
		
	}

	if (m_pBackground != NULL)
	{
		delete (m_pBackground);
		m_pBackground = NULL;
	}
	
	if (m_pEnemy != NULL)
	{
		delete (m_pEnemy);
		m_pEnemy = NULL;
	}
	
}

void CGameplay::Run()
{

	
	while (m_GameRun == true)
	{


		ProcessEvents();

		pFramework->Update();
		pFramework->clear();

		m_pBackground->render();

		m_pPlayer->update();
		m_pPlayer->render(90, 90, 90, 400.0f);

		m_pEnemy->Update();
		m_pEnemy->render(-90, -90, 270, 250.0f);

		

		pFramework->Render();

		
	}
}


void CGameplay::ProcessEvents()
{
	SDL_Event Event;

	if (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
			case(SDL_QUIT):
			{
				m_GameRun = false;
			} break;
			case(SDL_KEYDOWN):
			{
				switch (Event.key.keysym.sym)
				{
					case(SDLK_ESCAPE):
					{
						m_GameRun = false;
					}break;
				}
			}break;
		}
	}
}