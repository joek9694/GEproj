/*  TAS BORT VID KÖRNING

// ------------------------------ Övning -------------------------------------//
#include <SDL.h>


//preprocessor direktiv, har ett namn och resten av raden är definitionen.. överallt det står namnet, ersätts det med raden...
#define FPS 60

//För version 2 av Surface*
#include <string>
std::string path = "C:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/bg.bmp";

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);		// BORDE KOLLA if = -1 (fel svar) -> kolla föreläsningsbilder
	SDL_Window* win = SDL_CreateWindow("FonsterTitel", 100, 100, 700, 500, 0);	// 0 = olika flaggor som måste anges...

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);//För att kunna rita måste man ha renderarere motsvarar swings grafiksobject
													   // 2 representationer av surface, representerar en buffert i ram, texture* lämplig för videoram = grafdi kort
													   //version 1 //SDL_Surface* bgSurf = SDL_LoadBMP("C:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/bg.bmp");
													   //version 2	
	SDL_Surface* bgSurf = SDL_LoadBMP(path.c_str());

	SDL_Texture* bgTx = SDL_CreateTextureFromSurface(ren, bgSurf); // arg1 = renderare, arg2 = vilken surface ska förvandlas
	SDL_FreeSurface(bgSurf); //Surface behövs inte längre efter



	SDL_Surface* gubbSurf = SDL_LoadBMP("C:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/gubbe2.bmp");

	SDL_Rect gubbRect = { 0,0, gubbSurf->w, gubbSurf->h };	// pekare pekar ut underliggande struct, därför ->
	Uint32 white = SDL_MapRGB(gubbSurf->format, 255, 255, 255);
	SDL_SetColorKey(gubbSurf, true, white);

	SDL_Texture* gubbTx = SDL_CreateTextureFromSurface(ren, gubbSurf);

	SDL_FreeSurface(gubbSurf);

	// skriva ut saker -> sudda, skrivut bakgrund, sen skriv ut RenderCopy, klara med surface =freeSurface



	bool goOn = true;
	int varv = 0;
	bool drag = false;

	const int tickInterval = 1000 / FPS;
	while (goOn) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;

		SDL_Event eve;
		while (SDL_PollEvent(&eve)) {		//tar fram händelser från händelsekön, returnerar 1 om det fanns händelse i kön, annars 0.

			switch (eve.type) {

			case SDL_QUIT: goOn = false; break;
			case SDL_KEYDOWN:
				switch (eve.key.keysym.sym) {
				case SDLK_RIGHT: gubbRect.x++; break;		//hastighet kan styras genom flera pixlar åt gången.. tex.
				case SDLK_LEFT: gubbRect.x--; break;
				case SDLK_UP: gubbRect.y--; break;
				case SDLK_DOWN: gubbRect.y++; break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN: {
				SDL_Point p = { eve.button.x, eve.button.y };
				if (SDL_PointInRect(&p, &gubbRect))
					drag = true;

			}
									  break;

			case SDL_MOUSEBUTTONUP:
				drag = false;
				break;
			case SDL_MOUSEMOTION:
				if (drag) {
					gubbRect.x += eve.motion.xrel;
					gubbRect.y += eve.motion.yrel;
				}

			}// switch (kommer växa för alla möjliga händelser)

		}// Händelse loop!

		 // ------------------------- uppdatera tillstånd av figurer --------------------------------
		 //varv++;
		 //if(varv % 50 == 0)
		 //	gubbRect.x++;

		 //----------------------- obs!	utritning av figurer ---------------------------------------
		SDL_RenderClear(ren); // suddar i buffert som renderaren har för fönstret
		SDL_RenderCopy(ren, bgTx, NULL, NULL);	//spritecheets: om man inte vill skriva ut hela builden, styr atg3 & 4 
		SDL_RenderCopy(ren, gubbTx, NULL, &gubbRect);

		SDL_RenderPresent(ren);

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}// Huvud loop!






	 //SDL_Delay(5000);

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
*/