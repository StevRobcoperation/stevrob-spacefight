#ifndef FIGUR_HPP
#define FIGUR_HPP

#include<iostream>
#include"Sprite.hpp"
#include <list>
#include "Shot.hpp"


using namespace std;



class CFigur
{
	public:
		CFigur();
//		~CFigur();
		void Init(const char *name, const char *name2,
				int framewidth, int framewidth2,
				int frameheight, int frameheight2,
				int numframes, int numframes2); 
		void render(int degreePlayer , int degreeShot , int shotdirection, float speedshot);
		void lifebar(int deamgeG);
		void IsAlive();	
		int life() { return m_life; }					//zu testzewcken
		int *getdeamge() { return &m_demage; } 
		bool getalive() { return m_isAlive; }
		void Destroy(); 
		void ModifyShip(int armor, int canon);
		SDL_Rect GetRect() { return m_Rect; }
		list<CShot> *Getlist() { return &m_listofshots; } //Neu Neu
		

		

	protected:
		virtual void shooting(float firerate);

		int m_life;
		int m_demage;
		bool m_isAlive;
		CSprite *m_pSpriteShot;
		float m_fxPos;				
		float m_fyPos;				
		CSprite *m_pSpriteFigur;	
		float m_fanim;				
		list<CShot> m_listofshots;  //Neu Neu
		float xx;  
		SDL_Rect m_Rect;

};



#endif // !FIGUR_HPP

