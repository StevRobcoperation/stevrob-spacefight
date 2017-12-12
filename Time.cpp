#include "Time.hpp"


CTime::CTime()
{
	flastTime = SDL_GetTicks()/1000.0f;
	fcurrentTime = 0.0f;
	felapsed = 0.0f;
	//cout << "erstes last time : " << flastTime << endl;
}

void CTime::Update()
{
	//cout << "flasttime alt: " << flastTime << endl;
	fcurrentTime = SDL_GetTicks()/1000.0f;
	//cout << "currentime: " << fcurrentTime << endl;
	felapsed = fcurrentTime - flastTime;
	//cout << "elapsed: " << felapsed << endl;
	flastTime = fcurrentTime;
	//cout << "lasttime neu: " << flastTime << endl;

}

