#include "GameEngine.h"
#include <SDL.h>
#include "SdlHandler.h"

namespace ge {
	GameEngine::GameEngine()
	{
	}

	void GameEngine::add(Sprite* s) 
	{
		sprites.push_back(s);
	}

	void GameEngine::remove(Sprite* s) 
	{
		int i = 0;
		for (Sprite* spr : sprites) {
			if (s == spr) {				//Jämförelse operator korrekt??		Implementera operator== i Sprite ?!
				delete s;				// Syntax för delete???
				sprites.erase(sprites.begin() + i);
			}
				
			i++;
		}
		

	}

	void GameEngine::run()
	{
		bool go = true;
		const int tickInterval = 1000 / fps;

		while (go) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: go = false; break;

				case SDL_KEYDOWN:
					for (Sprite* s : sprites)
						s->keyDown(eve);
					break;
				}//switch
			}//inre while

			SDL_SetRenderDrawColor(sdlHandler.get_ren(), 255,255,255,255);
			SDL_RenderClear(sdlHandler.get_ren());

			for (Sprite* s : sprites) {
				s->tick();
				s->draw();
			}

			SDL_RenderPresent(sdlHandler.get_ren());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		}//yttre while
	}

	GameEngine::~GameEngine()
	{
	}
}



