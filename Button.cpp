#include "Button.hpp"


void CButton::Render()
{
	m_pSpriteButton->pos(m_fxPos, m_fyPos);
	m_pSpriteButton->render(m_fAnim, SDL_FLIP_NONE, NULL, 0);
}

void CButton::Init(float fxPos, float fyPos, CSprite *pSpriteButton, float fAnim)
{
	m_pSpriteButton = pSpriteButton;
	m_fxPos = static_cast<int>(fxPos);
	m_fyPos = static_cast<int>(fyPos);
	m_RectButton.x = static_cast<int>(fxPos);
	m_RectButton.y = static_cast<int>(fyPos);
	m_RectButton.h = pSpriteButton->GetRect().h;
	m_RectButton.w = pSpriteButton->GetRect().w;

	m_fAnim = fAnim;

	m_ButtonStatus = false;
}