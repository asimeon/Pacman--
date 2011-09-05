
#include <SDL.h>
#include "Timer.h"
#include "PacCore.h"
#include "PacMan.h"

int SDL_main(int argc, char* argv[])
{
	PacCore kCore;
	kCore.Initialise(1280, 720, false);

	bool bExit = false;

	Timer kTimer;
	SDL_Event kEvent;

	PacMan* pPacMan = new PacMan();
	pPacMan->LoadSpriteFromFile("data/block.png", 32, 32);
	pPacMan->SetScale(1.f);

	while(!bExit)
	{
		float fDeltaTime = (float)kTimer.GetDeltaTime();

		// update all items
		kCore.Update(fDeltaTime);

		// render objects
		kCore.Render(pPacMan);

		SDL_Flip(kCore.GetSurface());

		while(SDL_PollEvent(&kEvent))
		{
			switch(kEvent.type)
			{
			case SDL_QUIT:
				bExit = true;
				break;
			case SDL_KEYDOWN:
				{
					if( kEvent.key.keysym.sym == SDLK_ESCAPE )
						bExit = true;
				}
				break;
			}
		}
	}

	kCore.Uninitialise();
	return 0;
}
