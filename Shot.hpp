#ifndef SHOT_HPP
#define SHOT_HPP

#include "Sprite.hpp"

class CShot
{
	public:
		void Init(CSprite *pSpriteShot, float fxPos, float fyPos, int demage);
		void render(int degree);
		int getdemage() { return m_demage; }
		SDL_Rect GetRect () { return m_RectShot; }
		void moving(int shotdirection, float speed);
		void setexist(bool x);
		bool exist() { return m_bexist; }



	private:
		CSprite *m_pSpriteShot;
		int m_demage;
		bool m_bexist; // Existiert der Schuss noch ?
		float m_fxPos;
		float m_fyPos;
		SDL_Rect m_RectShot;
};


#endif // !
