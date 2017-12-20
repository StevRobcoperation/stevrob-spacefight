#ifndef BUTTON_HPP
#define BUTTON_HPP


#include "Sprite.hpp"

class CButton
{
	public:
		void Render();
		void Init(float fxPos, float fyPos, CSprite *m_pSpriteButton, float fAnim);
		bool GetButtonStatus() { return m_ButtonStatus; }
		SDL_Rect GetRect() { return m_RectButton; }

	private:
		bool m_ButtonStatus;
		float m_fxPos;
		float m_fyPos;
		SDL_Rect m_RectButton;
		CSprite *m_pSpriteButton;
		float m_fAnim;
};


#endif