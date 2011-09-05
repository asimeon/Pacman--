
#ifndef PACTILE_H
#define PACTILE_H

#include "PacObject.h"

class PacTile : public PacObject
{
public:
	PacTile();
	virtual ~PacTile();

	virtual void Initialise();
	virtual void Uninitialise();

	virtual void Update(float a_fDeltatime);
	virtual void Render(SDL_Surface* a_pScreen);
};

#endif // PACTILE_H
