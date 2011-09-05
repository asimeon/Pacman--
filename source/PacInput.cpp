
#include "PacInput.h"

PacInput::PacInput(SDL_Event* a_pEvent)
{
	m_pEvent = a_pEvent;
}

PacInput::~PacInput()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// \fn	void PacInput::UpdateKeys()
//
// \brief	Updates the keys.
//
// \author	Andrew
// \date	9/6/2011
////////////////////////////////////////////////////////////////////////////////////////////////////

void PacInput::UpdateKeys()
{
	while(SDL_PollEvent(m_pEvent))
	{
		if( m_pEvent->type != SDL_KEYDOWN || m_pEvent->type != SDL_KEYUP )
			continue;

		switch(m_pEvent->type)
		{
		case SDL_KEYDOWN:
			m_keys[m_pEvent->key.keysym.sym] = false;
			break;

		case SDL_KEYUP:
			m_keys[m_pEvent->key.keysym.sym] = true;
			break;

		default:
			break;
		}
	}
}
