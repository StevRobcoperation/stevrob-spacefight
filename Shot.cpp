#include "Shot.hpp"


void CShot::Init(CSprite *pSpriteShot, float fxPos, float fyPos, int demage)
{
	m_pSpriteShot = pSpriteShot;
	m_fxPos = static_cast<int> (fxPos);
	m_fyPos = static_cast<int>(fyPos);
	m_RectShot.h = pSpriteShot->GetRect().h;
	m_RectShot.w = pSpriteShot->GetRect().w;
	m_RectShot.x = static_cast<int>(fxPos);
	m_RectShot.y = static_cast<int>(fyPos);

	m_demage = demage;

//	cout << "x : " << m_RectShot.x << endl;
//	cout << "y: " << m_RectShot.y << endl;

	m_bexist = true;
}


void CShot::render(int degree)
{
	if (m_bexist == true)
	{
		m_pSpriteShot->pos(m_fxPos, m_fyPos); 
		m_pSpriteShot->render(SDL_FLIP_HORIZONTAL, NULL, degree);
	}
}

void CShot::moving(int shotdirection, float speed)
{
	switch (shotdirection)
	{
		case(90):
		{
			m_fxPos += speed * pTime->Getelapsed();
		}break;
		case(180):
		{
			m_fyPos += speed * pTime->Getelapsed();
		}break;
		case(270):
		{
			m_fxPos -= speed * pTime->Getelapsed();
		}break;
		case(360): // 0
		{
			m_fyPos -= speed * pTime->Getelapsed();
		}break;
	}

	m_RectShot.x = static_cast<int>(m_fxPos);
	m_RectShot.y = static_cast<int>(m_fyPos);

	if ((m_fxPos > 825.0f) || (m_fxPos < -25.0f))
		m_bexist = false;
	
	if ((m_fyPos > 625.0f) || (m_fyPos < -25.0f))
		m_bexist = false;
}

void CShot::setexist(bool x)
{
	m_bexist = x;
}