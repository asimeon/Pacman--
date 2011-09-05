
#include "PacLevel.h"
#include "PacCore.h"
#include "PacTile.h"

PacLevel::PacLevel()
{
	Initialise();
}

PacLevel::~PacLevel()
{
	Uninitialise();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacLevel::Initialise()
//
// \brief	Initialises this object.
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacLevel::Initialise()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacLevel::Uninitialise()
//
// \brief	Uninitialises this object.
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacLevel::Uninitialise()
{
	// delete all tiles
	PacTileVector::iterator iterTile = m_tiles.begin();
	for(; iterTile != m_tiles.end(); iterTile++)
	{
		PacTile* pTile = *iterTile;
		delete pTile;
	}
	m_tiles.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	bool PacLevel::AddTile( int a_iX, int a_iY, PacTile* a_pTile )
//
// \brief	Adds a tile.
//
// \author	Andrew
// \date	9/5/2011
//
// \param	a_iX		   	a i x coordinate.
// \param	a_iY		   	a i y coordinate.
// \param [in]	a_pTile	If non-null, a tile pointer.
//
// \return	true if it succeeds, false if it fails.
////////////////////////////////////////////////////////////////////////////////////////////////////

bool PacLevel::AddTile( int a_iX, int a_iY, PacTile* a_pTile )
{
	if( !a_pTile )
	{
		PacCore::DebugOutputMessage("AddTile: Uninitialised object.");
		return false;
	}

	a_pTile->SetPosition( Vector3f((float)a_iX, (float)a_iY, 0.0f) );
	m_tiles.push_back(a_pTile);

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacLevel::DebugDemoTiles()
//
// \brief	Debug demo tiles.
//
// \author	Andrew
// \date	9/5/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacLevel::DebugDemoTiles()
{
	PacTile* pTile = new PacTile;
	pTile->SetPosition(Vector3f(0.0f, 0.0f, 0.0f));
	pTile->LoadSpriteFromFile("data/block.png", 32, 32);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacLevel::Render( SDL_Surface* a_pScreen )
//
// \brief	Renders all tiles, if alive, to the screen.
//
// \author	Andrew
// \date	9/5/2011
//
// \param [in]	a_pScreen	If non-null, a pointer to the screen surface.
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacLevel::Render( SDL_Surface* a_pScreen )
{
	PacTileVector::iterator iterTile = m_tiles.begin();
	for(; iterTile != m_tiles.end(); iterTile++)
	{
		PacTile* pTile = *iterTile;

		if(pTile->GetToRender())
			pTile->Render(a_pScreen);
	}
}
