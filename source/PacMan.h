
#ifndef PACMAN_H
#define PACMAN_H

#include "PacObject.h"

class PacMan : public PacObject
{
public:
	PacMan();
	virtual ~PacMan();

	virtual void Initialise();
	virtual void Uninitialise();

	virtual void Update(float a_fDeltatime);
	virtual void Render(SDL_Surface* a_pScreen);

private:
	Vector3f m_kVelocity;
};

#endif // PACMAN_H
