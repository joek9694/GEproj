#include "GameEngine.h"

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
		}//yttre while
	}

	GameEngine::~GameEngine()
	{
	}
}



