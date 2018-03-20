#include "SdlHandler.h"
#include <SDL.h>

namespace ge {
	SdlHandler::SdlHandler()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("GE window", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1000, 750, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
	}


	SdlHandler::~SdlHandler()
	{
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	SDL_Window* SdlHandler::get_win() const
	{
		return win;
	}

	SDL_Renderer* SdlHandler::get_ren() const
	{
		return ren;
	}
	
	SdlHandler sdlHandler;		//statiskt objekt

}


