
#ifndef PACLEVEL_H
#define PACLEVEL_H

#include <map>
#include <SDL.h>

class PacTile;

class PacTilePosition
{
public:
	int x;
	int y;
};

typedef std::map<PacTilePosition, PacTile*> PacTileMap;

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
	PacTileMap m_tiles;

	bool m_bLoaded;
};

#endif // PACLEVEL_H
