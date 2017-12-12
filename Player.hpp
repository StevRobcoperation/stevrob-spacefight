#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Figur.hpp"


class CPlayer : public CFigur
{
	public:
		CPlayer();
		void update();
		void setstartpos();

	private:
		void move();
		void checkposition();



};





#endif
