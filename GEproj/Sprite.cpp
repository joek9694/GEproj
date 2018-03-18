#include "Sprite.h"
#include "SdlHandler.h"


namespace ge {

	void Sprite::draw() const {
		SDL_RenderCopy(sdlHandler.get_ren(), texture, NULL, &rect);
	}

	void Sprite::keyDown(const SDL_Event& eve) {
		switch (eve.key.keysym.sym) {
		case SDLK_RIGHT: rect.x ++; break;
		case SDLK_LEFT: rect.x--; break;
		case SDLK_UP: rect.y--; break;
		case SDLK_DOWN: rect.y++; break;
		}
	}



	Sprite::Sprite(int x, int y, int w, int h, SDL_Surface* s) : rect{ x,y,s->w,s->h } 
	{
		
		texture = SDL_CreateTextureFromSurface(sdlHandler.get_ren(),s);
		SDL_FreeSurface(s);
	}
	Sprite::Sprite(SDL_Surface* s)  
	{
		Uint32 white = SDL_MapRGB(s->format, 255, 255, 255);
		SDL_SetColorKey(s, true, white);
		texture = SDL_CreateTextureFromSurface(sdlHandler.get_ren(), s);
		rect = { 200,200, s->w,s->h };
		SDL_FreeSurface(s);
	}


	Sprite::~Sprite()
	{
	}
}


