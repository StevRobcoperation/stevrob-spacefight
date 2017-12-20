#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Player.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"


class CGameplay
{
	public:
		CGameplay();

		void Init();
		void Run();
		void Quit();

	private:
		void ProcessEvents();
		void CheckCollisions();

		CPlayer *m_pPlayer;
		CSprite *m_pBackground;
		CEnemy *m_pEnemy;
		CMenu *m_pMenu;
		bool m_GameRun;
		float zahler;
		bool m_bMenu;
		
	
};



#endif