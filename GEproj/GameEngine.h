#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"
#include "GameRules.h"

namespace ge {
	class GameEngine
	{
	public:
		GameEngine(GameRules* rules);		//Behövs?

		void add(Sprite*);
		void remove(Sprite*);
		void setFps(int newFps) { fps = newFps; };
		void run();
		~GameEngine();

	private:
		std::vector<Sprite*> sprites;		//Datasamling 
		GameRules* rules;
		int fps = 1000;
	};
}


#endif