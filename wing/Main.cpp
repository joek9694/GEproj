#include <SDL.h>
#include "Label.h"
#include "Session.h"
#include "Button.h"
#include <string>

using namespace std;
using namespace cwing;

int value = 0;		// global variabel

class OkaKnapp : public Button {		// Till�mpningsprogram! :)
public:
	OkaKnapp(Label* lbl) : Button(100, 100, 150, 70, "�ka") , label(lbl) {}
	void perform(Button* source) {
		value++;
		label->setText(to_string(value));
		source-> setRectX(15);		// Flytta bilden??
	}
private:
	Label* label;
};

class MinskaKnapp : public Button {		// Till�mpningsprogram! :)
public:
	MinskaKnapp(Label* lbl) : Button(500, 100, 150, 70, "Minska"), label(lbl) {}
	void perform(Button* source) {
		value--;
		label->setText(to_string(value));
		source->setRectX(getRect().x -15);		// Flytta bilden??
	}
private:
	Label * label;
};

// ------------------------------------------------------- MAIN -----------------------------------------

int main(int argc, char** argv) {
	Session ses;
	//Button*
	//Button*
	//ses.add
	//ses.add
	//ses.add
	//SDL_Delay(3000);

	Label* lbl = Label::getInstance(300, 100, 200, 70, "0");	//skapad p� stacken. Ska f�rbjudas, sista som s�gs f�rel�sning 11.
	ses.add(lbl);
	//Button* b = Button::getInstance(200,200, 200, 70, "Ok");
	Button* b = new OkaKnapp(lbl);
	ses.add(b);
	//lbl->setText("Hoppsan!");
	Button* b2 = new MinskaKnapp(lbl);
	ses.add(b2);
	ses.run();
	return 0;
}
