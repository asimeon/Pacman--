
#ifndef PACINPUT_H
#define PACINPUT_H

#include <SDL.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// \class	PacInput
//
// \brief	Input. Pacman's control scheme is very simple, we only need four buttons (Up/Down/Left/Right).
// 			
//
// \author	Andrew
// \date	9/6/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

class PacInput
{
public:
	PacInput(SDL_Event* a_pEvent);
	~PacInput();

	void UpdateKeys();

	inline bool IsKeyDown(int a_pSDLKey){ return m_keys[a_pSDLKey]; }

private:
	SDL_Event* m_pEvent;

	bool m_keys[SDLK_LAST];
};

#endif // PACINPUT_H
