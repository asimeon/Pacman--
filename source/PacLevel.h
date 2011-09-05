
#ifndef PACLEVEL_H
#define PACLEVEL_H

#include <vector>
#include <SDL.h>

class PacTile;

typedef std::vector<PacTile*> PacTileVector;

class PacLevel
{
public:
	PacLevel();
	virtual ~PacLevel();

	void Initialise();
	void Uninitialise();

	bool AddTile( int a_iX, int a_iY, PacTile* a_pTile);
	void DebugDemoTiles();

	void Render( SDL_Surface* a_pScreen );

protected:
	PacTileVector m_tiles;

	bool m_bLoaded;
};

#endif // PACLEVEL_H
