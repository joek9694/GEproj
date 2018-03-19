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
			if (s == spr) {				//J�mf�relse operator korrekt??		Implementera operator== i Sprite ?!
				delete s;				// Syntax f�r delete???
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
					// ----------------- TEMPOR�R---------------------------------
					if (eve.key.keysym.sym == SDLK_SPACE) {
						SDL_Surface* surf = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/genom3.png");
						Sprite* s = Sprite::getInstance(surf);
						sprites.push_back(s);
					}
					// ------------------------------------------------------------
					// ----------------- TEMPOR�R---------------------------------
					if (eve.key.keysym.sym == SDLK_BACKSPACE) {

						sprites.clear();
						/*for (Sprite* s : sprites) {
							remove(s);
						}*/
							
					}
					// ------------------------------------------------------------
					break;
				}//switch
			}//inre while

			SDL_SetRenderDrawColor(sdlHandler.get_ren(), 255,255,255,255);
			SDL_RenderClear(sdlHandler.get_ren());

			// ----------------- TEMPOR�RT BEVIS ---------------------------------
			Sprite* s1 = sprites[0];
			Sprite* s2 = sprites[1];
			if (s1->collision(s2)) {
				std::cout << "javisst" << std::endl;
			}
			// --------------------------------------------------------------------

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



