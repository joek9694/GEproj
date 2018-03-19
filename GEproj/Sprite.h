#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include<iostream>
#include<string.h>

namespace ge {
	class Sprite
	{
	public:
		~Sprite();
		static Sprite* getInstance(SDL_Surface*);
		virtual void draw() const;		// abstrakt funktion ? , som i så fall Måste implementeras i subklass	// = 0 för rent virtuell
		virtual void tick() { };		// tom funktion... lr?
		virtual void keyDown(const SDL_Event&);
		bool collision(const Sprite*) const;
		const SDL_Rect& getRect() const{ return rect; }
		void setRectX(int x) { rect = {x, rect.y, rect.w, rect.h }; };
		void setRectY(int y) { rect = {rect.x, y, rect.w, rect.h }; };


	protected:
		Sprite(int x, int y, int w, int h, SDL_Surface* s);		//BEHÖVS?
		Sprite(SDL_Surface* s);

	private: 
		SDL_Texture* texture;
		SDL_Surface* surf;
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;		// Förbjud tilldelning
		const Sprite& operator=
			(const Sprite&) = delete;		// Förbjud kopiering
	};
}


#endif 
