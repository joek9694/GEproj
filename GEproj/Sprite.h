#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace ge {
	class Sprite
	{
	public:
		Sprite();
		~Sprite();
		virtual void draw() const = 0;		// abstrakt funktion, som Måste implementeras i subklass
		virtual void tick() const {};		// tom funktion... lr?
		const SDL_Rect& getRect() const{ return rect; }
	private: 
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;		// Förbjud tilldelning
		const Sprite& operator=
			(const Sprite&) = delete;		// Förbjud kopiering
	};
}


#endif 
