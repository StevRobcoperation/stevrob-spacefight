#include"Figur.hpp"

CFigur::CFigur()
{
//	*m_life = 100;
//	m_demage = 15;
	m_pSpriteFigur = NULL;
}

/*
CFigur::~CFigur()
{
	//Sprite zb "Yeah" ausgeben
}

*/
/*
void CFigur::lifebar(int demageG)
{
	*m_life -= demageG;
	
}
*/

/*
bool CFigur::IsAlive()
{
	if (*m_life <= 0)
		return false;
	else
		return true;
}
*/

//const char *name, int framewidth, int frameheight, int numframes

void CFigur::Init(const char *name, const char *name2,
				  int framewidth, int framewidth2,
				  int frameheight, int frameheight2,
				  int numframes, int numframes2)
{
	m_pSpriteFigur = new CSprite;
	m_pSpriteFigur->load(name, framewidth, frameheight, numframes);

	if (name2 != NULL)
	{
		m_pSpriteShot = new CSprite;
		m_pSpriteShot->load(name2, framewidth2, frameheight2, numframes2);
	}
}

void CFigur::render(int degreePlayer, int degreeShot , int shotdirection, float speedshot)
{

	//if (IsAlive())
	//{
	m_pSpriteFigur->pos(m_fxPos, m_fyPos);
	m_pSpriteFigur->render(m_fanim, SDL_FLIP_HORIZONTAL, NULL, degreePlayer);
	//}

	list<CShot>::iterator i = m_listofshots.begin();

	while (i != m_listofshots.end())
	{
		i->moving(shotdirection, speedshot);

		if (i->exist())
		{
			i->moving(shotdirection, speedshot);
			i->render(degreeShot);
			i++;
		}
		else
		{
			i = m_listofshots.erase(i);
		}
	}
}

void CFigur::Destroy()
{
	if (m_pSpriteFigur != NULL)
	{
		delete (m_pSpriteFigur);
		m_pSpriteFigur = NULL;
	}
	if (m_pSpriteShot != NULL)
	{
		delete (m_pSpriteShot);
		m_pSpriteShot = NULL;
	}
}

void CFigur::shooting(float firerate)
{
	

	xx += pTime->Getelapsed();
	

	if (xx >= firerate)
	{
		CShot Shot;
		Shot.Init(m_pSpriteShot, m_fxPos, m_fyPos);

		m_listofshots.push_back(Shot);

		xx = 0.0f;
	}


}




