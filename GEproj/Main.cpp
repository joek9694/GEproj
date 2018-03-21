#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>

#include "GameEngine.h"
#include "SdlHandler.h"
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
// ---------------------------------Sprite1------------------------------------------------
class Sprite1 : public Sprite {

public:
	Sprite1(SDL_Surface* sur) : Sprite(sur) {}
	Sprite1(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
	virtual void keyDown(const SDL_Event&) {};
	void tick() {
		if (moveInverter) {

			if (i <= 50) {
				//cout << getRect().x << endl;
				setRectX(getRect().x - 2);
			}
			else if (i <= 100) {
				//cout << getRect().x << endl;
				setRectX(getRect().x - 2);
				if (i == 100) {
					i = 0;
					moveInverter = false;
				}
			}

		}
		else {
			if (i <= 50) {
				//cout << getRect().x << endl;
				setRectX(getRect().x + 1);
			}
			else if (i <= 100) {
				//cout << getRect().x << endl;
				setRectX(getRect().x - 1);
				if (i == 100) {
					i = 0;
				}
			}
		}
		i++;

	};

	void perform(Sprite* source) {
		setRectX(getRect().x - 1);
		moveInverter = true;
	}
private:
	int i = 0;
	bool moveInverter = false;

};
// ----------------------Experiment-------------------------------------
class Sprite2 : public Sprite {

public:
	Sprite2(SDL_Surface* sur) : Sprite(sur) {}
	Sprite2(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
	virtual void keyDown(const SDL_Event&) {};
	void tick() {
		if (i <= 430) {
			//cout << getRect().x << endl;
			setRectX(getRect().x + 2);
		}
		else if (i <= 860) {
			//cout << getRect().x << endl;
			setRectX(getRect().x - 2);
		}
		if (i == 860) {
			i = 0;
		}
		i++;

	};
	void score() {
		s++;
		cout << "Computer: " << endl;
		cout << s << endl;
	}
private:
	int i = 0;
	int s = 0;

};
/*
class Sprite2 : public Sprite {

public:
Sprite2(SDL_Surface* sur) : Sprite(sur) {}
Sprite2(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
virtual void keyDown(const SDL_Event&) {};
void tick() {
if (i <= 475) {
//cout << getRect().x << endl;
setRectX(getRect().x + 1);
}
else if (i <= 950) {
//cout << getRect().x << endl;
setRectX(getRect().x - 1);
}
if (i == 950) {
i = 0;
}
i++;

};
private:
int i = 0;

};*/


// ----------------------------------------Player----------------------------------------
class Player : public Sprite {

public:
	Player(SDL_Surface* sur) : Sprite(sur) {}
	Player(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
	void tick() {

	};

	void Sprite::keyDown(const SDL_Event& eve) {
		switch (eve.key.keysym.sym) {
		case SDLK_RIGHT: setRectX(getRect().x + 5); break;
		case SDLK_LEFT: setRectX(getRect().x - 5); break;
		case SDLK_UP: setRectY(getRect().y - 5); break;
		case SDLK_DOWN: setRectY(getRect().y + 5); break;
		}
	}

	void score() {
		s++;
		cout << "Player: " << endl;
		cout << s << endl;
	}

private:
	int i = 0;
	int s = 0;

};

// ------------------------------------ball-----------------------------------
class Ball : public Sprite {

public:
	Ball(SDL_Surface* sur) : Sprite(sur) {}
	Ball(int x, int y, int w, int h, SDL_Surface* sur, Player* p, Sprite2* s2)
		: Sprite(x, y, w, h, sur), p(p), comp(s2) {
	}
	virtual void keyDown(const SDL_Event&) {};

	void tick() {
		if (getRect().y <= 1000 && getRect().y >= 0) {
			if (getRect().x >= 950 || getRect().x <= 0) {
				horizontal_speed = horizontal_speed * -1;
				setRectX(getRect().x + (horizontal_speed / 10));
			}

			if (collision(p)) {
				moveInverter = true;
			}
			if (collision(comp)) {
				moveInverter = false;
				int cX = comp -> getRect().x;
				int cW = comp -> getRect().w;
				int cMid = cX + (cW / 2);
				horizontal_speed = midPos - cMid;

			}
			if (moveInverter) {
				setRectY(getRect().y - 2);
			}
			else {
				setRectY(getRect().y + 2);
			}

			setRectX(getRect().x + (horizontal_speed / 10));
			i++;
		}
		else {
			moveInverter = !moveInverter;
			if (moveInverter) {
				setRectY(getRect().y - 2);
				comp -> score();
			}
			else {
				setRectY(getRect().y + 2);
				p -> score();
			}
		}

		// Reset???

	};

	void perform(Sprite* source) {
	}

private:
	int i = 0;
	bool moveInverter = false;
	int midPos = getRect().x + (getRect().w / 2);
	int horizontal_speed = 0;
	Player* p;
	Sprite2* comp;

};

// ----------------------------------------------------- main---------------------------------

int main(int argc, char** argv) {
	GameEngine ge;
	int middle = 237;
	//SDL_Surface* surf = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/genom3.png");

	//SDL_Surface* gubbSurf = SDL_LoadBMP(
	//	"c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Gubbe.bmp");

	SDL_Surface* sUPP = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Uppknapp.png");
	SDL_Surface* sNER = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Ner2.png");
	SDL_Surface* pNER = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Nerknapp.png");
	SDL_Surface* pUPP = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Upp2.png");
	SDL_Surface* ball = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Ball.png");


	//Sprite1* s = new Sprite1(0,0, 200,200,sUPP);
	//ge.add(s);

	Sprite2* s2 = new Sprite2(0, 0, 50, 50, sNER);
	ge.add(s2);

	Player* p = new Player(middle, 700, 50, 50, pUPP);
	ge.add(p);

	Ball* b = new Ball(590, 300, 200, 200, ball, p, s2);
	ge.add(b);

	ge.setFps(100);


	// -----------------OBS!!!!!------------------ 
	/*
	SDL_Rect r = s->getRect();
	int* y = &r.y;
	cout << *y << endl;


	cout << "----------1-----------" << endl;
	cout << *&r.x << endl;
	cout << *&r.y << endl;
	cout << *&r.w << endl;
	cout << *&r.h << endl;
	*/
	cout << "----------2-----------" << endl;
	SDL_Rect r2 = s2->getRect();
	cout << *&r2.x << endl;
	cout << *&r2.y << endl;
	cout << *&r2.w << endl;
	cout << *&r2.h << endl;

	cout << "----------3-----------" << endl;
	SDL_Rect r3 = p->getRect();
	cout << *&r3.x << endl;
	cout << *&r3.y << endl;
	cout << *&r3.w << endl;
	cout << *&r3.h << endl;

	cout << "----------4-----------" << endl;
	SDL_Rect r4 = b->getRect();
	cout << *&r4.x << endl;
	cout << *&r4.y << endl;
	cout << *&r4.w << endl;
	cout << *&r4.h << endl;
	//--------------------------------------------

	ge.run();
	return 0;
};

