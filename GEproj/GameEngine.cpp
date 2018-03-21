#include "GameEngine.h"
#include <SDL.h>
#include "SdlHandler.h"
#include <SDL_image.h>

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
		bool active = false;
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
					// ----------------- TEMPORÄR---------------------------------
					if (eve.key.keysym.sym == SDLK_SPACE) {
						SDL_Surface* surf = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/genom3.png");
						//Sprite* s = Sprite::getInstance(surf);
						//sprites.push_back(s);
						SDL_FreeSurface(surf);
					}
					// ------------------------------------------------------------
					// ----------------- TEMPORÄR---------------------------------
					if (eve.key.keysym.sym == SDLK_BACKSPACE) {

						//sprites.clear();
						
						remove(sprites[0]);
						
							
					}
					// ------------------------------------------------------------
					break;
				}//switch
			}//inre while

			SDL_SetRenderDrawColor(sdlHandler.get_ren(), 255,255,255,255);
			SDL_RenderClear(sdlHandler.get_ren());

			// ----------------- TEMPORÄRT BEVIS ---------------------------------

			// --------------------------------------------------------------------

			for (Sprite* s : sprites) {
				auto temp = this;
				s->tick(temp);
				s->draw();
			}

			SDL_RenderPresent(sdlHandler.get_ren());

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



