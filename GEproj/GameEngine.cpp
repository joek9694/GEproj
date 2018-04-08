#include "GameEngine.h"
#include <SDL.h>
#include "SdlHandler.h"
#include <SDL_image.h>



namespace ge {
	GameEngine::GameEngine(GameRules* rules): rules(rules)
	{
	}

	void GameEngine::add(Sprite* s) 
	{
		sprites.push_back(s);
	}

	//deletes 1 sprite from Sprites
	void GameEngine::remove(Sprite* s) 
	{
		int count = 0;
		int i = 0;
		bool found = false;
		while (!found && i < sprites.size()) {
			Sprite* temp = sprites[i];

			if (temp == s) {
				sprites.erase(sprites.begin() + i);	//sprites.begin() + i
				// dealloc... delete själva objektet
				//(GameRules::Sprite1 *)
				delete dynamic_cast<GameRules::Sprite1*>(temp);
				found = true;
			}
			else {
				i++;
			}
			count++;
		}
		
			//std::cout << sprites.size() << std::endl;		//sprites = innehåller bara spelare, dator och boll

	}

	void GameEngine::run()
	{
		bool go = true;
		bool active = false;
		const int tickInterval = 1000 / fps;

		while (go) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			auto temp = this;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: go = false; break;

				case SDL_KEYDOWN:
					for (Sprite* s : sprites)
						s->keyDown(eve, temp);
					
					break;
				}//switch
			}//inre while

			SDL_SetRenderDrawColor(sdlHandler.get_ren(), 255,255,255,255);
			SDL_RenderClear(sdlHandler.get_ren());

			for (Sprite* s : sprites) {
				
				s->tick(temp);
				s->draw();
			}

			SDL_RenderPresent(sdlHandler.get_ren());

			rules->special(this);

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
			active = true;
		}//yttre while
	}

	GameEngine::~GameEngine()
	{

	}
}



