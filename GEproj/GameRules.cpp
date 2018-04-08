#include "GameRules.h"
#include <SDL_image.h>
#include "GameEngine.h"

namespace ge {

	GameRules::GameRules()
	{
	}
	void GameRules::special(GameEngine * G_E)
	{	
		//Original filepath
		//c:Prog3/inlupp/images/
		if (count % 1000 == 0 && count > 999) {
			SDL_Surface* ball2 = IMG_Load("C:/Users/Johan.Eklundh/Desktop/Prog3/inlupp/images/Ball2.png");
			Sprite1* s = new Sprite1(count / 10, count / 10, 200, 200, ball2);
			Sprite1* s2 = s;
			G_E->add(s);
			spr.push_back(s2);
			
		}
		if (count <= 3500) {
			count++;
		}
		else {
			count = 0;
			//std::vector<Sprite*>::iterator it = spr.begin();
			int i = spr.size() - 1;

			while (i >= 0) {	//			Breakpoint!?
				Sprite1* temp = spr[i];
				G_E->remove(temp);
				i--;
			}
			spr.clear();
			//tebax in i while?
			
			/*
			for (size_t i = 0; i < spr.size(); ++i) {
				delete spr[i];
			}
			spr.clear();
			*/
			/*
			while (!spr.empty()) {
				delete spr.back();
				spr.pop_back();
			}
			*/
			


			/*
			int i2 = spr.size();
			while (i2 > 0) {
				Sprite1* sp = (Sprite1*)(*(spr.end() - 1));
				spr.erase(spr.end() - 1);
				// dealloc... delete själva objektet
				delete sp;
				i2--;
			}
			*/
			//std::cout << spr.size() << std::endl;			// spr = helt tömd
		}
		
	}


	GameRules::~GameRules()
	{
	}
}


