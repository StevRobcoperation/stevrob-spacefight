#include "Enemy.hpp"


CEnemy::CEnemy()
{
	m_pSpriteFigur = NULL;
	m_pSpriteShot = NULL;
}

void CEnemy::Update()
{
	IsAlive();

	move();
	
	CanonPos(1, -20.0f, 11.0f, 0.0f, 0.0f);

	shooting(0.5f);

	checkpos();
}


void CEnemy::setstartpos(float fxPos, float fyPos)
{
	m_fxPos = fxPos;
	m_fyPos = fyPos;
	m_fanim = 0.0f;
	m_Rect.x = static_cast<int>(m_fxPos);
	m_Rect.y = static_cast<int>(m_fyPos);
	m_move = true;
}


void CEnemy::move()
{
	if (m_move == true)
	{
		m_fyPos -= 200.0f * pTime->Getelapsed();
	}
	else
		m_fyPos += 200.0f * pTime->Getelapsed();

	m_Rect.x = static_cast<int>(m_fxPos);
	m_Rect.y = static_cast<int>(m_fyPos);

}


void CEnemy::checkpos()
{
	if (m_fyPos < 0.0f)
	{
		m_fyPos = 0.0f;
		m_move = false;
	}
	if (m_fyPos > 536.0f)
	{
		m_fyPos = 536.0f;
		m_move = true;

	}
}

