#include "GameEngine.h"
#include <SDL.h>
#include "SdlHandler.h"

namespace ge {
	GameEngine::GameEngine()
	{
	}


	void GameEngine::run()
	{
		bool go = true;

		while (go) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: go = false; break;
				}//switch
			}//inre while

			SDL_SetRenderDrawColor(sdlHandler.get_ren(), 255,255,255,255);
			SDL_RenderClear(sdlHandler.get_ren());

			for (Sprite* s : sprites) {
				s->tick();
				s->draw();
			}

			SDL_RenderPresent(sdlHandler.get_ren());
		}//yttre while
	}

	GameEngine::~GameEngine()
	{
	}
}



