#ifndef SDLHANDLER_H
#define SDLHANDLER_H

#include <SDL.h>
#include <SDL_ttf.h>

namespace ge {
	class SdlHandler
	{
	public:
		SdlHandler();
		~SdlHandler();
		SDL_Renderer* get_ren() const;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
	};

	extern SdlHandler sdlHandler;
}


#endif
