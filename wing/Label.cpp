#include "Label.h"
#include<SDL_ttf.h>
#include "System.h"

namespace cwing {
	Label::Label(int x, int y, int w, int h, std::string txt): Component(x,y,w,h), text(text)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {0,0,0});
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
	}

	void Label::draw() const {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
	}

	Label::~Label()
	{
		SDL_DestroyTexture(texture);
	}
}


