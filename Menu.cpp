#include "Menu.hpp"

CMenu::CMenu() 
{
	m_pMenuB = NULL;
	m_pButton = NULL;


}
void CMenu::Init(const char *nameBg, const char *nameBu, int framewidthBu, int framehightBu)
{
	m_pMenuB = new CSprite;
	m_pMenuB->load(nameBg);


	m_pButton = new CSprite;
	m_pButton->load(nameBu, framewidthBu, framehightBu, 2);

	CButton Button;

	Button.Init(277.5f, 150.0f, m_pButton, 0.0f);

	m_ListButton.push_back(Button);

	Button.Init(277.5f, 300.0f, m_pButton, 1.0f);

	m_ListButton.push_back(Button);


	m_Buttonstatus = false;

}

void CMenu::Render()
{
	m_pMenuB->render();

	list<CButton>::iterator i = m_ListButton.begin();

	while (i != m_ListButton.end())
	{
		i->Render();

		++i;

	}

}

void CMenu::Destroy()
{
	if (m_pMenuB != NULL)
	{
		delete (m_pMenuB);
		m_pMenuB = NULL;
	}
	if (m_pButton != NULL)
	{
		delete (m_pButton);
		m_pButton = NULL;
	}
}

