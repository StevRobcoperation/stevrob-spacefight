#ifndef Menu_HPP
#define Menu_HPP

#include "Sprite.hpp"
#include "Button.hpp"
#include <list>


class CMenu
{
	public:
		CMenu();
		void Destroy();
		void Init(const char *nameBg, const char *nameBu, // Bg = Background, Bu = Button
									  int framewidthBu,
									  int framehightBu);
//		void CheckButton();
		void Render();
		bool GiveButtonstatus() { return m_Buttonstatus; }
//		void ChooseButton();

	private:
		bool m_Buttonstatus;
		CSprite *m_pMenuB;
		list<CButton> m_ListButton;
		CSprite *m_pButton;
		


		




};




#endif
