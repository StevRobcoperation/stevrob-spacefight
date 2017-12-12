#ifndef TIME_HPP
#define TIME_HPP

#include "Singelton.hpp"
#include <SDL.h>
#include <iostream>
using namespace std;

#define pTime CTime::Get()

class CTime : public TSingelton<CTime>
{
	public:
		CTime();
		void Update();
		float Getelapsed() { return felapsed; }
		

	private:
		float flastTime;
		float fcurrentTime;
		float felapsed;


};




#endif
