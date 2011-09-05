
#include "PacCore.h"
#include <SDL_image.h>
#include "PacObject.h"

PacCore::PacCore()
	: m_bInitialised(false)
{
	m_pScreen = NULL;
}

PacCore::~PacCore()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacCore::Initialise( float a_fWidth, float a_fHeight, bool a_bFullscreen )
//
// \brief	Initialises this object.
//
// \author	Andrew
// \date	9/5/2011
//
// \param	a_fWidth	 	Width of the window.
// \param	a_fHeight	 	Height of the window.
// \param	a_bFullscreen	If true, fullscreen.
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacCore::Initialise( float a_fWidth, float a_fHeight, bool a_bFullscreen )
{
	m_pScreen = NULL;

	int iError = SDL_Init(SDL_INIT_VIDEO);
	if( iError )
	{
		DebugOutputMessage("ERROR: Could not initialise SDL.");
	}

	int iFlags = SDL_HWSURFACE | SDL_DOUBLEBUF;
	if( a_bFullscreen )
	{
		iFlags |= SDL_FULLSCREEN;
	}

	m_pScreen = SDL_SetVideoMode((int)a_fWidth, (int)a_fHeight, 32, iFlags);

	// load images
	iError = IMG_Init(IMG_INIT_PNG);
	if( iError )
	{
		DebugOutputMessage("ERROR: Could not initialise SDL image.");
	}

	m_bInitialised = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacCore::Uninitialise()
//
// \brief	Uninitialises this object.
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacCore::Uninitialise()
{
	if(m_pScreen)
	{
		SDL_FreeSurface(m_pScreen);
		m_pScreen = NULL;
	}

	PacObjectVector::iterator iterObject = m_vObjects.begin();
	for(; iterObject != m_vObjects.end(); ++iterObject)
	{
		PacObject* pObject = *iterObject;
		delete pObject;
	}

	m_vObjects.clear();

	IMG_Quit();
	SDL_Quit();

	m_bInitialised = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacCore::Update( float a_fDeltatime )
//
// \brief	Updates the given a_fDeltatime.
//
// \author	Andrew
// \date	9/5/2011
//
// \param	a_fDeltatime	The deltatime.
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacCore::Update( float a_fDeltatime )
{
	PacObjectVector::iterator iterObject = m_vObjects.begin();
	for(; iterObject != m_vObjects.end(); ++iterObject)
	{
		PacObject* pObject = *iterObject;
		if( pObject->GetToRender() )
			pObject->Update(a_fDeltatime);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacCore::Render( SDL_Surface* a_pSurface )
//
// \brief	Renders the given surface to screen.
//
// \author	Andrew
// \date	9/5/2011
//
// \param [in,out]	a_pSurface	If non-null, screen surface.
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacCore::Render( PacObject* a_pObject )
{
	if(!m_pScreen)
	{
		DebugOutputMessage("ERROR: null screen surface.");
		return;
	}

	if( !a_pObject->GetToRender() )
		return;

	SDL_Rect kRect;
	kRect.x = (Sint16)a_pObject->GetPosition().x;
	kRect.y = (Sint16)a_pObject->GetPosition().y;
	kRect.w = (Sint16)a_pObject->GetSpriteWidth()  /** (Sint16)a_pObject->GetScale()*/; // scaling doesn't work.
	kRect.h = (Sint16)a_pObject->GetSpriteHeight() /** (Sint16)a_pObject->GetScale()*/; // todo: figure out another way.
	SDL_BlitSurface(a_pObject->GetSurface(), NULL, m_pScreen, &kRect);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacCore::DebugOutputMessage( std::string a_ssString )
//
// \brief	Debug an output message.
//
// \author	Andrew
// \date	9/5/2011
//
// \param	a_ssString	The string to output.
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacCore::DebugOutputMessage( std::string a_ssString )
{
#ifdef _DEBUG
	printf("%s\n", a_ssString.c_str());
#endif
}
