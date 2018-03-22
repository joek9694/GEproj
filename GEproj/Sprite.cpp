#include "Sprite.h"
#include "SdlHandler.h"


namespace ge {
	//------------------------konstruktorer---------------------------------
	Sprite::Sprite(int x, int y, int w, int h, SDL_Surface* s)
	{
		
		Uint32 white = SDL_MapRGB(s->format, 255, 255, 255);
		SDL_SetColorKey(s, true, white);
		texture = SDL_CreateTextureFromSurface(sdlHandler.get_ren(), s);
		rect = { x,y, s->w, s->h };
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

	//-----------------------------destruktor---------------------------------
	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
	}

	//------------------------------metoder------------------------------------

	void Sprite::draw() const {
		SDL_RenderCopy(sdlHandler.get_ren(), texture, NULL, &rect);
	}

	bool Sprite::collision(const Sprite * s) const
	{
		SDL_Rect r = s->getRect();
		if (SDL_HasIntersection(&rect, &r)) {
			return true;
		}
		return false;
	}



	
}


