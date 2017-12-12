#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Framework.hpp"



class CSprite
{

	public:
		CSprite();
		~CSprite();
		void load(const char *name);
		void load(const char *name, int framewidth, int frameheight, int numframes); //Neu
		void render();
		void render(const SDL_RendererFlip Flip, const SDL_Point *center, const double angel);
		void render(float number, const SDL_RendererFlip Flip, const SDL_Point *center, const double angel);
		void pos(float xpos, float ypos);
		SDL_Rect GetRect() { return m_bild; }
		


	private:
		SDL_Texture *m_pimage;
		SDL_Renderer *m_prenderer;
		SDL_Rect m_bild;
		SDL_Rect m_anim;
		int m_numframes;   //Neu
		int m_framewidth;  //Neu
		int m_frameheight; //Neu
		int m_numframesR;  //Neu



};


#endif

