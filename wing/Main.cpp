#include <SDL.h>
#include "Label.h"
#include "Session.h"
using namespace cwing;

int main(int argc, char** argv) {
	Session ses;
	//Button*
	//Button*
	//ses.add
	//ses.add
	//ses.add
	//SDL_Delay(3000);

	Label lbl(100, 100, 200, 70, "Hej");	//skapad på stacken. Ska förbjudas, sista som sägs föreläsning 11.
	ses.add(&lbl);
	ses.run();
	return 0;
}
