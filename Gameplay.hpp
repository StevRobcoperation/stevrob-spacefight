#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Player.hpp"
#include "Enemy.hpp"


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
		bool m_GameRun;
		
	
};



#endif