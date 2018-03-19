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

	//-----------------------------destruktor-----------------------------------
	Sprite::~Sprite()
	{
	}

	//------------------------------metoder------------------------------------
	Sprite* Sprite::getInstance(SDL_Surface* s) {
		return new Sprite(s);
	}

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

	bool Sprite::collision(const Sprite * s) const
	{
		
		/*
		Inte färdigt... kollar bara under rätt förutsättning... 
rektanglar kan ju vara olika stora..

		int leftX = rect.x;
		int rightX = rect.x + rect.w;
		int upperY = rect.y;
		int lowerY = rect.y + rect.h;
		bool withinX = s->rect.x <= rightX && s->rect.x >= leftX;
		bool withinY = s->rect.y >= upperY && s->rect.y <= lowerY;
		if (withinX && withinY) {
			return true;
		}
		*/
		SDL_Rect r = s->getRect();
		if (SDL_HasIntersection(&rect, &r)) {
			return true;
		}
		return false;
	}



	
}


