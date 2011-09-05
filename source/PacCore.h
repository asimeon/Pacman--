
#ifndef PACCORE_H
#define PACCORE_H

#include <conio.h>
#include <string>
#include <vector>

#include <SDL.h>

class PacObject;

////////////////////////////////////////////////////////////////////////////////////////////////////
// \class	PacCore
//
// \brief	Pacman core. 
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

typedef std::vector<PacObject*> PacObjectVector;

class PacCore
{
public:
	PacCore(float a_fWidth, float a_fHeight, bool a_bFullscreen);
	~PacCore();

	void Initialise(float a_fWidth, float a_fHeight, bool a_bFullscreen);
	void Uninitialise();

	void Update(float a_fDeltatime);
	void Render( PacObject* a_pObject );

	static void DebugOutputMessage( std::string a_ssString );

	inline SDL_Surface* GetSurface() const { return m_pScreen; }

	void AddObject(PacObject* a_pObject);

	inline int GetWindowWidth() const { return m_iWindowWidth; }
	inline int GetWindowHeight() const { return m_iWindowHeight; }

private:
	SDL_Surface* m_pScreen;
	bool m_bInitialised;

	int m_iWindowWidth;
	int m_iWindowHeight;

	PacObjectVector m_vObjects;
};

#endif // PACCORE_H
