
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

void PacLevel::Initialise()
{

}

void PacLevel::Uninitialise()
{

}

bool PacLevel::AddTile( int a_iX, int a_iY, PacTile* a_pTile )
{
	if( !a_pTile )
	{
		PacCore::DebugOutputMessage("AddTile: Uninitialised object.");
		return false;
	}

	PacTilePosition kPos;
	kPos.x = a_iX;
	kPos.y = a_iY;

	m_tiles.insert(PacTileMap::make_pair(kPos, a_pTile));

	return true;
}

void PacLevel::DebugDemoTiles()
{

}

void PacLevel::Render( SDL_Surface* a_pScreen )
{

}
