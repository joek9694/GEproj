#ifndef LABEL_H
#define LABEL_H
#include "Component.h"
#include <string>
#include <SDL.h>

// Konvention: använd INTE 'using namespace' i en header-fil!

namespace cwing {
	class Label: public Component
	{
	public:
		Label(int x, int y, int w, int h, std::string txt);
		void draw() const;
		~Label();
	private:
		std::string text;
		SDL_Texture* texture;
	};
}


#endif

