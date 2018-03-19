#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>


#include "GameEngine.h"

// Kommentarer = tips!

// 1: Obs! föreläsning 8: statiska objekt -> 
		//35 min till 38 min på föreläsningsinspelning
		//kan användas för t.ex. sdl:init() och sdl:quit(), före respektive efter main().

// 2: Skriv alltid const i funktionshuvudet när du har en funktion som inte förändrar objektet!
		// Allså const både i deklaration och definition!
		// gäller endast icke-statiska medlemsfunktioner...

// 3: Vanliga funktioner FÅR INTE definieras i headerfiler, utan Måste definieras i cpp-filer

// 4: Inline funktioner, klassdefinitioner och mallar placeras i headerfiler normalt sett


using namespace ge;
using namespace std;

class Sprite1 : public Sprite {

public:
	Sprite1(SDL_Surface* sur) : Sprite(sur) {}
	Sprite1(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x,y,w,h,sur) {}
	void tick() {
			if (i <=50) {
				//cout << getRect().x << endl;
				setRectX(getRect().x + 1);
			}else if (i <=100) {
				//cout << getRect().x << endl;
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

class Sprite2 : public Sprite {

public:
	Sprite2(SDL_Surface* sur) : Sprite(sur) {}
	Sprite2(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
	void tick() {
		if (i <= 30) {
			//cout << getRect().x << endl;
			setRectX(getRect().x + 1);
		}
		else if (i <= 100) {
			//cout << getRect().x << endl;
			setRectX(getRect().x - 1);	
		}
		if (i == 100) {
			i = 0;
		}
		i++;

	};
private:
	int i = 0;

};

int main(int argc, char** argv) {
	GameEngine ge;
	//SDL_Surface* surf = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/genom3.png");

	//SDL_Surface* gubbSurf = SDL_LoadBMP(
	//	"c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Gubbe.bmp");

	SDL_Surface* sUPP = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Uppknapp.png");
	SDL_Surface* sNER = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Nerknapp.png");


	Sprite1* s = new Sprite1(sUPP);
	ge.add(s);

	Sprite2* s2 = new Sprite2(900,200,50,50, sNER);
	ge.add(s2);
	ge.setFps(30);


	// -----------------OBS!!!!!------------------ 
	
	SDL_Rect r = s->getRect();
	int* y = &r.y;
	cout << *y << endl;


	cout << "----------1-----------" << endl;
	cout << *&r.x << endl;
	cout << *&r.y << endl;
	cout << *&r.w << endl;
	cout << *&r.h << endl;
	
	cout << "----------2-----------" << endl;
	SDL_Rect r2 = s2->getRect();
	cout << *&r2.x << endl;
	cout << *&r2.y << endl;
	cout << *&r2.w << endl;
	cout << *&r2.h << endl;
	//--------------------------------------------
	
	ge.run();
	return 0;
};

