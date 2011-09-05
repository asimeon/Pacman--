
#include <SDL.h>
#include "Timer.h"
#include "PacCore.h"
#include "PacMan.h"
#include "PacLevel.h"

int SDL_main(int argc, char* argv[])
{
	PacCore kCore(1280, 720, false);

	bool bExit = false;

	Timer kTimer;
	SDL_Event kEvent;

	PacMan* pPacMan = new PacMan();
	kCore.AddObject(pPacMan);

	PacLevel kLevel;
	kLevel.DebugDemoTiles();

	Uint32 uiClear = SDL_MapRGB(kCore.GetSurface()->format, 13,13,255);
	SDL_Rect kClearRect;
	kClearRect.x = 0;
	kClearRect.y = 0;
	kClearRect.w = kCore.GetWindowWidth();
	kClearRect.h = kCore.GetWindowHeight();

	while(!bExit)
	{
		SDL_FillRect(kCore.GetSurface(), &kClearRect, uiClear);

		float fDeltaTime = (float)kTimer.GetDeltaTime();

		// update all items
		kCore.Update(fDeltaTime);

		// render objects
		kLevel.Render(kCore.GetSurface());
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
