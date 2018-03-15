#ifndef COMPONENT_H
#define COMPONENT_H
#include<SDL.h>
namespace cwing {
	class Component
	{
	public:
		virtual ~Component();
		virtual void mouseDown(const SDL_Event&) {};	//tom funktionen, men kan �verskuggas vid behov i subklasser
		virtual void mouseUp(const SDL_Event&) {};
		virtual void keyDown(const SDL_Event&) {};
		virtual void keyUp(const SDL_Event&) {};
		virtual void draw() const = 0;	// = 0 inneb�r abstrakt funktion, varje subklass M�ste implementera den
		const SDL_Rect& getRect() const { return rect; }
	protected:
		Component(int x, int y, int w, int h);		// Protected s� att det inte g�r att skapa object av denna klass utanf�r klasshierarkin.
	private:
		SDL_Rect rect;
		Component(const Component&) = delete;		// F�rbjuder tilldelning
		const Component& operator=(const Component&) = delete;		// F�rbjuder kopiering
	};
}

#endif