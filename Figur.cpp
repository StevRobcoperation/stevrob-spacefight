#include"Figur.hpp"

CFigur::CFigur()
{
	
	m_pSpriteShot = NULL;
	m_pSpriteFigur = NULL;
}

/*
CFigur::~CFigur()
{
	//Sprite zb "Yeah" ausgeben
}

*/

void CFigur::lifebar(int demageG)
{
	m_life -= demageG;
	

}



void CFigur::IsAlive()
{
	if (m_life <= 0)
		m_isAlive = false;
	else
		m_isAlive = true;
}


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

	m_Rect.h = m_pSpriteFigur->GetRect().h;
	m_Rect.w = m_pSpriteFigur->GetRect().w;

	m_life = 100;
	m_demage = 20;
	m_isAlive = true;
}

void CFigur::render(int degreePlayer, int degreeShot , int shotdirection, float speedshot)
{

	
	

	m_pSpriteFigur->pos(m_fxPos, m_fyPos);

	m_pSpriteFigur->render(m_fanim, SDL_FLIP_HORIZONTAL, NULL, degreePlayer);


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
	list<SCanon>::iterator Ca = m_listofcanons.begin();

	if (xx >= firerate)
	{

		
		while (Ca != m_listofcanons.end())
		{
	
			CShot Shot; 
			Shot.Init(m_pSpriteShot, Ca->fXPosC, Ca->fyPosC, m_demage);


			m_listofshots.push_back(Shot);
//			cout << "Wert Ca: " << Ca->fXPosC << endl;
			Ca++;
		}
		
		xx = 0.0f;
	}
	
	m_listofcanons.clear();

	

}

void CFigur::ModifyShip(int amor, int canon)
{
	m_demage += canon;
	m_life += amor;
}


void CFigur::CanonPos(int num, float fxPos1, float fyPos1, float fxPos2, float fyPos2)
{
	
	m_NumCanons = num;

	int pos[4] = { fxPos1, fyPos1, fxPos2, fyPos2 };

	int counter  = 0;

	for (int i = 0; i < num; i++)
	{
		SCanon Canon;
		Canon.fXPosC = pos[counter] + m_fxPos;
//		cout << "Counter: " << pos[counter] << endl;
		counter++;
		Canon.fyPosC = pos[counter] + m_fyPos;
//		cout << "Counter2: " << pos[counter] << endl;
		counter++;
		m_listofcanons.push_back(Canon);
	}
}