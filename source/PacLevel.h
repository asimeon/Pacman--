
#ifndef PACLEVEL_H
#define PACLEVEL_H

#include <map>
#include <SDL.h>
#include "PacTile.h"

typedef std::map<const char*, PacTile*> PacTileMap;

class PacLevel
{
public:
	PacLevel();
	virtual ~PacLevel();

	void Initialise();
	void Uninitialise();

	void DebugDemoTiles();

	void Render( SDL_Surface* a_pScreen );

protected:
	PacTileMap m_tiles;

	bool m_bLoaded;
};

#endif // PACLEVEL_H
