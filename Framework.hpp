#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP



#include <SDL.h>
#include <iostream>
#include "Singelton.hpp"
#include "Time.hpp"
using namespace std;

#define  pFramework CFramework::Get()

class CFramework : public TSingelton<CFramework>
{
	public:
		CFramework();
		bool Init(int screendWidth, int screenHeight, bool screen);
		void Destroy();
		void Render();
		void Update();
		bool Keydown(int Key_Id);
		void clear();
		SDL_Renderer *GetRenderer() { return renderer; }

		//audio

	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		const Uint8 *keystate;



};


#endif