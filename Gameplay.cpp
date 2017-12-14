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
	m_pPlayer->Init("Data/Player.bmp", "Data/Laser2.bmp",64, 10, 64, 31, 11, 0);
	m_pPlayer->setstartpos();
	m_pPlayer->ModifyShip(100, 30);
  
	m_pBackground = new CSprite;
	m_pBackground->load("Data/Background.bmp");

	m_pEnemy = new CEnemy;
	m_pEnemy->Init("Data/Player.bmp", "Data/Laser2.bmp", 64, 20, 64, 40, 11, 0);
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


//		cout << "Raumschiff alive: " << m_pEnemy->getalive() << endl;
		if (m_pPlayer->getalive())
		{
			m_pPlayer->update();
			m_pPlayer->render(90, 90, 90, 400.0f);
		}
	
		if (m_pEnemy != NULL)
		{
			if (m_pEnemy->getalive())
			{
				m_pEnemy->Update();
				m_pEnemy->render(-90, -90, 270, 250.0f);
			}
			if (!m_pEnemy->getalive())
			{
				m_pEnemy->Destroy();
				delete (m_pEnemy);
				m_pEnemy = NULL;
			}
		}

		CheckCollisions();

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

void CGameplay::CheckCollisions()
{
	list<CShot> *ShotListP = m_pPlayer->Getlist();
//	list<CShot> *ShotListE = m_pEnemy->Getlist();

	list<CShot>::iterator It;

	SDL_Rect RectPlayer, RectEnemy, RectShot;

	RectPlayer = m_pPlayer->GetRect();
	if (m_pEnemy != NULL)
	{
		RectEnemy = m_pEnemy->GetRect();

		for (It = ShotListP->begin(); It != ShotListP->end(); ++It)
		{
			RectShot = It->GetRect();

			//		cout << "Shot.x: " << RectShot.x << endl;
			//		cout << "Shot.y: " << RectShot.y << endl;
			//		cout << "Enemy.y: " << RectEnemy.y << endl;

			if (RectShot.y < RectEnemy.y + RectEnemy.h &&
				RectShot.y + RectShot.h  > RectEnemy.y &&
				RectShot.x < RectEnemy.x + RectEnemy.w &&
				RectShot.x + RectShot.w > RectEnemy.x)
			{
				m_pEnemy->lifebar(It->getdemage());
				It->setexist(false);

				cout << "Life: " << m_pEnemy->life() << endl;
			}
		}
	}
	
}