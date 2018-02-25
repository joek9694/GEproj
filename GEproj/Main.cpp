#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>

// Kommentarer = tips!

// 1: Obs! föreläsning 8: statiska objekt -> 
		//35 min till 38 min på föreläsningsinspelning
		//kan användas för t.ex. sdl:init() och sdl:quit(), före respektive efter main().

// 2: Skriv alltid const i funktionshuvudet när du har en funktion som inte förändrar objektet!
		// Allså const både i deklaration och definition!
		// gäller endast icke-statiska medlemsfunktioner...

// 3: Vanliga funktioner FÅR INTE definieras i headerfiler, utan Måste definieras i cpp-filer

// 4: Inline funktioner, klassdefinitioner och mallar placeras i headerfiler normalt sett

class GameEngine {
public:

private:
};

int main(int argc, char** argv) {

	return 0;
};

