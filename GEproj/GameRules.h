#ifndef GAMERULES_H
#define GAMERULES_H
#include <vector>
#include "Sprite.h"
namespace ge {

	class GameEngine;

	class GameRules{
	public:
		GameRules();
		~GameRules();

		void special(GameEngine* G_E);

		class Sprite1 : public Sprite {

		public:
			Sprite1(SDL_Surface* sur) : Sprite(sur) {}
			Sprite1(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {
			}
			~Sprite1() {
			}

			virtual void keyDown(const SDL_Event&, GameEngine* G_E) {};

			void tick(GameEngine* G_E) {};

		};

	private:
		std::vector<Sprite1*> spr;		// datasamling

		int count = 0;
	};
}


#endif // !GAMERULES_H


