#include "Sprite.hpp"

CSprite::CSprite()
{
	m_prenderer = pFramework->GetRenderer();
}

CSprite::~CSprite()
{
	SDL_DestroyTexture(m_pimage);
}

void CSprite::load(const char *name)
{
	SDL_Surface *surface = SDL_LoadBMP(name);

	if (surface == NULL)
	{
		cout << "Fehler beim laden von: " << *name << "      "<< SDL_GetError();

		pFramework->Destroy();

		exit(1);

	}
	

	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));

	m_pimage = SDL_CreateTextureFromSurface(m_prenderer, surface);

	SDL_FreeSurface(surface);

	m_bild.x = 0;
	m_bild.y = 0;
	m_bild.h = surface->h;
	m_bild.w = surface->w;
	


}

//Neu
void CSprite::load(const char *name, int framewidth, int frameheight, int numframes)
{
	load(name);
	
	m_numframes = numframes;
	m_framewidth = framewidth;
	m_frameheight = frameheight;
	m_anim.w = framewidth;
	m_anim.h = frameheight;
	m_numframesR = m_bild.w / m_framewidth;

	m_bild.w = framewidth;
	m_bild.h = frameheight;
}

void CSprite::render()
{
	SDL_RenderCopy(m_prenderer, m_pimage, NULL, &m_bild);
}


void CSprite::render(const SDL_RendererFlip Flip, const SDL_Point *center, const double angel)
{
	SDL_RenderCopyEx(m_prenderer, m_pimage, NULL, &m_bild, angel, center, Flip);

}

//Neu
void CSprite::render(float fnumber, const SDL_RendererFlip Flip, const SDL_Point *center, const double angel)
{
	int column = static_cast<int>(fnumber) % m_numframesR;
	int row = static_cast<int>(fnumber) / m_numframes;
	m_anim.x = column * m_framewidth;
	m_anim.y = row * m_frameheight;
	

	SDL_RenderCopyEx(m_prenderer, m_pimage, &m_anim, &m_bild, angel, center, Flip);
}

void CSprite::pos(float xpos, float ypos)
{
	m_bild.x = static_cast<int> (xpos);
	m_bild.y = static_cast<int> (ypos);
}