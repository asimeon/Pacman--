
#include "PacObject.h"
#include <SDL_image.h>

PacObject::PacObject()
{
	Initialise();
}

PacObject::~PacObject()
{
	Uninitialise();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacObject::Initialise()
//
// \brief	Initialises this object.
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacObject::Initialise()
{
	m_pSurface = NULL;

	m_kPosition = Vector3f::ZERO();
	m_fScale = 1.f;

	m_iSurfaceWidth = 0;
	m_iSurfaceHeight = 0;

	m_bRender = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacObject::Uninitialise()
//
// \brief	Uninitialises this object.
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacObject::Uninitialise()
{
	if(m_pSurface)
	{
		SDL_FreeSurface(m_pSurface);
		m_pSurface = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacObject::LoadSpriteFromFile( std::string a_ssFilename )
//
// \brief	Loads a sprite from file.
//
// \author	Andrew
// \date	9/5/2011
//
// \param	a_ssFilename	Filename of a ss file.
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacObject::LoadSpriteFromFile( std::string a_ssFilename, int a_iWidth, int a_iHeight )
{
	m_iSurfaceWidth = a_iWidth;
	m_iSurfaceHeight = a_iHeight;

	m_pSurface = IMG_Load(a_ssFilename.c_str());
}
