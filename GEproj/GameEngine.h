#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"

namespace ge {
	class GameEngine
	{
	public:
		GameEngine();		//Behövs?

		void add(Sprite* s);
		void remove(Sprite* s);
		void run();
		~GameEngine();

	private:
		std::vector<Sprite*> sprites;		//Datasamling 
	};
}


#endif