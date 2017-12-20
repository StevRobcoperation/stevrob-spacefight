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
	m_pPlayer->ModifyShip(0, 5);
  
	m_pBackground = new CSprite;
	m_pBackground->load("Data/Background.bmp");

	m_pEnemy = new CEnemy;
	m_pEnemy->Init("Data/Playerex.bmp", "Data/Laser2.bmp", 64, 20, 64, 40, 3, 0);
	m_pEnemy->setstartpos(700.0f, 268.0f);

	m_pMenu = new CMenu;
	m_pMenu->Init("Data/StartBild.bmp", "Data/PlayButton.bmp", 245, 76);
	


	m_bMenu = true;
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
	
	if (m_pMenu != NULL)
	{
		delete(m_pMenu);
		m_pMenu = NULL;
	}
}

void CGameplay::Run()
{


	while (m_GameRun == true)
	{


		ProcessEvents();

		pFramework->Update();
		pFramework->clear();
		if (m_bMenu == true)
		{
			m_pMenu->Render();
		}
		else
		{
			m_pBackground->render();
			//	cout << "Raumschiff alive: " << m_pEnemy->getalive() << endl;
			if (m_pPlayer != NULL)
			{
				if (m_pPlayer->getalive())
				{
					m_pPlayer->update();
					m_pPlayer->render(90, 90, 90, 400.0f);
				}

				if (!m_pPlayer->getalive())
				{
					m_pPlayer->Destroy();
					delete (m_pPlayer);
					m_pPlayer = NULL;

				}
			}


			if (m_pEnemy != NULL)
			{
				if (m_pEnemy->getalive())
				{
					m_pEnemy->Update();
					m_pEnemy->render(-90, -90, 270, 300.0f);
				}
				if (!m_pEnemy->getalive())
				{
					m_pEnemy->SetAnim(1.0f);
					m_pEnemy->render(-90, -90, 270, 250.0f);

					zahler += pTime->Getelapsed();
					if (zahler > 0.3f)
					{
						m_pEnemy->Destroy();
						delete (m_pEnemy);
						m_pEnemy = NULL;
						zahler = 0.0f;

					}
				}

				CheckCollisions();

				pFramework->Render();


			}
		}
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
	
	
	
	list<CShot>::iterator It;

	SDL_Rect RectPlayer, RectEnemy, RectShotp, RectShote;

	
	if ((m_pEnemy != NULL) && (m_pPlayer != NULL))
	{
		list<CShot> *ShotListP = m_pPlayer->Getlist();
		RectPlayer = m_pPlayer->GetRect();
		RectEnemy = m_pEnemy->GetRect();

		for (It = ShotListP->begin(); It != ShotListP->end(); ++It)
		{
			RectShotp = It->GetRect();

		//			cout << "Shot.x: " << RectShot.x << endl;
			//		cout << "Shot.y: " << RectShot.y << endl;
				//	cout << "Enemy.y: " << RectEnemy.y << endl;

			if (RectShotp.y < RectEnemy.y + RectEnemy.h &&
				RectShotp.y + RectShotp.h  > RectEnemy.y &&
				RectShotp.x < RectEnemy.x + RectEnemy.w &&
				RectShotp.x + RectShotp.w > RectEnemy.x)
			{
				m_pEnemy->lifebar(It->getdemage());
				It->setexist(false);

//				cout << "Life: " << m_pEnemy->life() << endl;
			}
		}
	}


	

	if ((m_pPlayer != NULL) && (m_pEnemy != NULL))
	{
		list<CShot> *ShotListE = m_pEnemy->Getlist();
		RectEnemy = m_pEnemy->GetRect();
		RectPlayer = m_pPlayer->GetRect();
	
		for (It = ShotListE->begin(); It != ShotListE->end(); ++It)
		{
			RectShote = It->GetRect();

//			cout << "Shot.x: " << RectShote.x << endl;
//			cout << "Shot.y: " << RectShote.y << endl;

			if (RectShote.y < RectPlayer.y + RectPlayer.h &&
				RectShote.y + RectShote.h  > RectPlayer.y &&
				RectShote.x < RectPlayer.x + RectPlayer.w &&
				RectShote.x + RectShote.w > RectPlayer.x)
			{
				m_pPlayer->lifebar(It->getdemage());
				It->setexist(false);

//				cout << "demagr gegener: " << It->getdemage() << endl;
//				cout << "life:" << m_pPlayer->life() << endl;

			}

		}	
	
	
	
	}

		


}