#include "Player.hpp"


CPlayer::CPlayer()
{
	m_pSpriteFigur = NULL;
	m_pSpriteShot = NULL;
}

void CPlayer::setstartpos()
{
	m_fxPos = 0.0f;
	m_fyPos = 268.0f;

	m_fanim = 5.0f;
}

void CPlayer::move()
{
	if (pFramework->Keydown(SDL_SCANCODE_A))
	{
		m_fxPos -= 300.0f * pTime->Getelapsed();
		m_fanim = 5.0f;//20.0f * pTime->Getelapsed();
		
	}
	else if (pFramework->Keydown(SDL_SCANCODE_D))
	{
		

		if (pFramework->Keydown(SDL_SCANCODE_S))
		{
			m_fyPos += 200.0f * pTime->Getelapsed();
			m_fxPos += 250.0f *pTime->Getelapsed();
			m_fanim -= 20.0f * pTime->Getelapsed();
		}
		else if (pFramework->Keydown(SDL_SCANCODE_W))
		{
			m_fyPos -= 200.0f * pTime->Getelapsed();
			m_fxPos += 250.0f * pTime->Getelapsed();
			m_fanim += 20.0f * pTime->Getelapsed();

		}
		else
		{
			m_fxPos += 300.0f * pTime->Getelapsed();
			m_fanim = 5.0f;//20.0f * pTime->Getelapsed();
		}


	}
	else if (pFramework->Keydown(SDL_SCANCODE_W))
	{
		m_fyPos -= 300.0f * pTime->Getelapsed();
		m_fanim = 5.0f;
	}
	else if (pFramework->Keydown(SDL_SCANCODE_S))
	{
		m_fyPos += 300.0f * pTime->Getelapsed();
		m_fanim = 5.0f;
	}
	else
		m_fanim = 5.0f;
	
	
	
	
	
	
}


void CPlayer::checkposition()
{
	if (m_fxPos < 00.0f)
	{
		m_fxPos = 00.0f;
	}
	else if (m_fxPos > 864.0f)
	{
		m_fxPos = 0.0f;
	}
	else if (m_fyPos < 0.0f)
	{
		m_fyPos = 0.0f;
	}
	else if (m_fyPos > 536.0f)
	{
		m_fyPos = 536.0f;
	}

	if (m_fanim < 0.0f)
	{
		m_fanim = 1.0f;
	}
	else if (m_fanim > 10.0f)
	{
		m_fanim = 10.0f;
	}
}


void CPlayer::update()
{
	move();

	CanonPos(2, 29.0f, -11.0f, 29.0f, 44.0f);

	shooting(0.7f);

	checkposition();
}