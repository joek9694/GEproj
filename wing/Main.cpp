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

	Label lbl(100, 100, 200, 70, "Hej");	//skapad p� stacken. Ska f�rbjudas, sista som s�gs f�rel�sning 11.
	ses.add(&lbl);
	ses.run();
	return 0;
}
