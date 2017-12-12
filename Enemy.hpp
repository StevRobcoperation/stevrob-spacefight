#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Figur.hpp"

class CEnemy : public CFigur
{
	public:
		CEnemy();
		void Update();
		void setstartpos(float fxPos, float fyPos);

	private:
		void move();
		void checkpos();
		bool m_move;
};



#endif
