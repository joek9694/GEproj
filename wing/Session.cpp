#include <SDL.h>
#include "Session.h"
#include "System.h"

namespace cwing {
	
	void Session::add(Component* c) {
		comps.push_back(c);
	}

	void Session::run() {
		bool quit = false;

		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN: 
					for (Component* c : comps)
						c->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : comps)
						c->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (Component* c : comps)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (Component* c : comps)
						c->keyUp(eve);
					break;
				}//switch
			}//inre while
			
			// DESSA STEG F�R ATT UPPDATERA GRAFIKEN
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());

			for (Component* c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());
		}//yttre while
	}

	Session::~Session()
	{
	}

}


