#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>


#include "GameEngine.h"

// Kommentarer = tips!

// 1: Obs! f�rel�sning 8: statiska objekt -> 
		//35 min till 38 min p� f�rel�sningsinspelning
		//kan anv�ndas f�r t.ex. sdl:init() och sdl:quit(), f�re respektive efter main().

// 2: Skriv alltid const i funktionshuvudet n�r du har en funktion som inte f�r�ndrar objektet!
		// Alls� const b�de i deklaration och definition!
		// g�ller endast icke-statiska medlemsfunktioner...

// 3: Vanliga funktioner F�R INTE definieras i headerfiler, utan M�ste definieras i cpp-filer

// 4: Inline funktioner, klassdefinitioner och mallar placeras i headerfiler normalt sett


using namespace ge;
using namespace std;

class Sprite1 : public Sprite {

public:
	Sprite1(SDL_Surface* sur) : Sprite(sur) {}
	void tick() {
			if (i <=50) {
				cout << getRect().x << endl;
				setRectX(getRect().x + 1);
			}else if (i <=100) {
				cout << getRect().x << endl;
				setRectX(getRect().x - 1);
				if (i == 100) {
					i = 0;
				}
			}
		
			
		i++;

	};
private:
	int i = 0;

};

int main(int argc, char** argv) {
	GameEngine ge;
	SDL_Surface* surf = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/genom3.png");

	
	Sprite1* s = new Sprite1(surf);
	ge.add(s);
	ge.setFps(100);

	ge.run();
	return 0;
};

