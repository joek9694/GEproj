#ifndef LABEL_H
#define LABEL_H
#include "Component.h"
#include <string>
#include <SDL.h>

// Konvention: anv�nd INTE 'using namespace' i en header-fil!
// p.g.a (inkluderas av till�mpningsprogram) man ska inte �ppna namespaces f�r till�mpningar

namespace cwing {
	class Label: public Component
	{
	public:
		static Label* getInstance(int x, int y, int w, int h, std::string txt);
		void draw() const;
		std::string getText() const;
		void setText(std::string newText);
		~Label();
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	private:
		std::string text;
		SDL_Texture* texture;
	};
}


#endif

