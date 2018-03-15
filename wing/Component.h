#ifndef COMPONENT_H
#define COMPONENT_H
#include<SDL.h>
namespace cwing {
	class Component
	{
	public:
		virtual ~Component();
		virtual void mouseDown(const SDL_Event&) {};	//tom funktionen, men kan överskuggas vid behov i subklasser
		virtual void mouseUp(const SDL_Event&) {};
		virtual void keyDown(const SDL_Event&) {};
		virtual void keyUp(const SDL_Event&) {};
		virtual void draw() const = 0;	// = 0 innebär abstrakt funktion, varje subklass Måste implementera den
		const SDL_Rect& getRect() const { return rect; }
	protected:
		Component(int x, int y, int w, int h);		// Protected så att det inte går att skapa object av denna klass utanför klasshierarkin.
	private:
		SDL_Rect rect;
		Component(const Component&) = delete;		// Förbjuder tilldelning
		const Component& operator=(const Component&) = delete;		// Förbjuder kopiering
	};
}

#endif