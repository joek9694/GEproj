#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include<iostream>
#include<string.h>

namespace ge {
	class GameEngine;
	
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void draw() const;
		virtual void tick(GameEngine*) = 0;
		virtual void perform(Sprite* source) {};
		virtual void keyDown(const SDL_Event&, GameEngine*)=0;
		bool collision(const Sprite*) const;
		const SDL_Rect& getRect() const{ return rect; }
		void setRectX(int x) { rect = {x, rect.y, rect.w, rect.h }; };
		void setRectY(int y) { rect = {rect.x, y, rect.w, rect.h }; };


	protected:
		Sprite(int x, int y, int w, int h, SDL_Surface* s);
		Sprite(SDL_Surface* s);

	private: 
		SDL_Texture* texture;			
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;		// Förbjud tilldelning
		const Sprite& operator=
			(const Sprite&) = delete;		// Förbjud kopiering
	};
}


#endif 
