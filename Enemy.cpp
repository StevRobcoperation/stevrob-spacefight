#include "Enemy.hpp"


CEnemy::CEnemy()
{
	m_pSpriteFigur = NULL;
	m_pSpriteShot = NULL;
}

void CEnemy::Update()
{
	move();

	shooting(1.5f);

	checkpos();
}


void CEnemy::setstartpos(float fxPos, float fyPos)
{
	m_fxPos = fxPos;
	m_fyPos = fyPos;
	m_fanim = 5.0f;
	m_move = true;
}


void CEnemy::move()
{
	if (m_move == true)
	{
		m_fyPos -= 150.0f * pTime->Getelapsed();
	}
	else
		m_fyPos += 150.0f * pTime->Getelapsed();
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
