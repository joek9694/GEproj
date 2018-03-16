#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace ge {
	class Sprite
	{
	public:
		Sprite();
		~Sprite();
		virtual void draw() const = 0;		// abstrakt funktion, som M�ste implementeras i subklass
		virtual void tick() const {};		// tom funktion... lr?
		const SDL_Rect& getRect() const{ return rect; }
	private: 
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;		// F�rbjud tilldelning
		const Sprite& operator=
			(const Sprite&) = delete;		// F�rbjud kopiering
	};
}


#endif 
