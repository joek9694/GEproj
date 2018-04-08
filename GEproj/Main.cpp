#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>

#include "GameEngine.h"
#include "SdlHandler.h"


using namespace ge;
using namespace std;

// ----------------------Experiment-------------------------------------
class Sprite2 : public Sprite {

public:
	Sprite2(SDL_Surface* sur) : Sprite(sur) {}
	Sprite2(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
	virtual void keyDown(const SDL_Event&, GameEngine* G_E) {};
	void tick(GameEngine* G_E) {
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
// ----------------------------------------Player----------------------------------------
class Player : public Sprite {

public:
	Player(SDL_Surface* sur) : Sprite(sur) {}
	Player(int x, int y, int w, int h, SDL_Surface* sur) : Sprite(x, y, w, h, sur) {}
	
	void tick(GameEngine* G_E) {};

	void Sprite::keyDown(const SDL_Event& eve, GameEngine* G_E) {
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
	virtual void keyDown(const SDL_Event& eve, GameEngine* G_E) {
	};

	void tick(GameEngine* G_E) {
		if (getRect().y <= 700 && getRect().y >= 0) {

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
			if (i == 1000) {
				i = 0;
			}
			else {
				i++;
			}
			
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
	};

	void perform(Sprite* source) {
	}
protected:


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
	/*
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int * intPtr = new int;
	*intPtr = 10;
	cout << intPtr << " " << *intPtr << endl;
	*/
	GameRules* gr = new GameRules();
	GameEngine* ge = new GameEngine(gr);
	int middle = 237;
	
	// Original filepath
	//c:Prog3/inlupp/images/

	SDL_Surface* sNER = IMG_Load("C:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Ner2.png");
	SDL_Surface* pUPP = IMG_Load("C:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Upp2.png");
	SDL_Surface* ball = IMG_Load("C:/Users/Johan.Eklundh/Desktop/Prog3/inlupp/images/Ball.png");
	//C:\Users\Johan.Eklundh\Desktop\Prog3\inlupp\images
	//SDL_Surface* ball2 = IMG_Load("c:Prog3/inlupp/images/Ball2.png");

	

	Sprite2* s2 = new Sprite2(0, 0, 50, 50, sNER);
	ge ->add(s2);

	Player* p = new Player(middle, 700, 50, 50, pUPP);
	ge ->add(p);

	Ball* b = new Ball(590, 300, 200, 200, ball, p, s2);
	ge ->add(b);

	ge ->setFps(400);

	ge ->run();
	return 0;
};

