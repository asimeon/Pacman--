
#include "PacTile.h"

PacTile::PacTile()
{
	Initialise();
}

PacTile::~PacTile()
{
	Uninitialise();
}

void PacTile::Initialise()
{
	m_iSurfaceWidth = 32;
	m_iSurfaceHeight = 32;
}

void PacTile::Uninitialise()
{

}

void PacTile::Update( float a_fDeltatime )
{

}

void PacTile::Render( SDL_Surface* a_pScreen )
{

}
