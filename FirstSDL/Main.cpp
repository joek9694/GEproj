#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include <string>
using namespace std;
#define FPS 20 //frames per second

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 36);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);

	Mix_Chunk* musik = Mix_LoadWAV("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/bgMusic.wav");
	Mix_Chunk* skott = Mix_LoadWAV("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/klick.wav");
	SDL_Window* win = SDL_CreateWindow("MyWindow",
		100, 100, 700, 500, 0);	//0 = SDL_WindowShown

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
	SDL_Surface* bgSurf = SDL_LoadBMP(
		"c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/hello_world.bmp");
	SDL_Texture* bgTx = SDL_CreateTextureFromSurface(ren, bgSurf);
	SDL_FreeSurface(bgSurf);


	SDL_Surface* gubbSurf = SDL_LoadBMP(
		"c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/Gubbe.bmp");
	SDL_Rect gubbRect = { 0,0, gubbSurf->w, gubbSurf->h };
	Uint32 white = SDL_MapRGB(gubbSurf->format, 255, 255, 255);
	SDL_SetColorKey(gubbSurf, true, white);
	SDL_Texture* gubbTx = SDL_CreateTextureFromSurface(ren, gubbSurf);
	SDL_FreeSurface(gubbSurf);


	SDL_Surface* pacSurf = IMG_Load("c:/Users/Johan.Eklundh/Desktop/Visual Studio/workspace/prog3_GEproj/images and sounds/genom3.png");
	SDL_Texture* pacTx = SDL_CreateTextureFromSurface(ren, pacSurf);
	SDL_Rect pacRect = { 200, 200, pacSurf->w, pacSurf->h };
	SDL_FreeSurface(pacSurf);


	bool goOn = true;
	int varv = 0;
	bool drag = false;
	bool dragP = false;

	const int tickInterval = 1000 / FPS;

	int channel = Mix_PlayChannel(-1, musik, 0);
	int channel2 = Mix_PlayChannel(-1, skott, 0);
	//Mix_Volume(channel, 10);
	Mix_Volume(-1, 10);
	while (goOn) {		//huvudloop!
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event eve;
		while (SDL_PollEvent(&eve)) {
			switch (eve.type) {
			case SDL_QUIT: goOn = false;
				break;
			case SDL_KEYDOWN:
				switch (eve.key.keysym.sym) {
				case SDLK_RIGHT: gubbRect.x += 2; break;	//ex, snabbare rörelse... rörelse begränsat av bl.a. uppdateringsfrekvens av keybuttons
				case SDLK_LEFT: gubbRect.x--; break;
				case SDLK_UP: gubbRect.y--;
					Mix_Volume(channel, gubbRect.y);
					break;
				case SDLK_DOWN: gubbRect.y++;
					Mix_Volume(channel, gubbRect.y);
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN: {
				SDL_Point p = { eve.button.x, eve.button.y };
				if (SDL_PointInRect(&p, &gubbRect)) {
					drag = true;
				}
				if (SDL_PointInRect(&p, &pacRect)) {
					dragP = true;
				}
				Mix_PlayChannel(-1, skott, 0);
			}
									  break;
			case SDL_MOUSEBUTTONUP:
				drag = false;
				dragP = false;
				break;
			case SDL_MOUSEMOTION:
				if (drag) {
					gubbRect.x += eve.motion.xrel;	//obs! +=
					gubbRect.y += eve.motion.yrel;
				}
				if (dragP) {
					pacRect.x += eve.motion.xrel;
					pacRect.y += eve.motion.yrel;
				}
				break;
			}//switch
		}

		/*varv++;	//ett sätt att fördröja
		if(varv % 50 == 0)
		gubbRect.x++;*/

		varv++;
		string varvStr = to_string(varv);

		SDL_Color svart = { 0,0,0 };
		SDL_Surface* varvSurf =
			TTF_RenderText_Solid(font, varvStr.c_str(), svart);
		SDL_Texture* varvTx = SDL_CreateTextureFromSurface(ren, varvSurf);
		SDL_Rect varvRect = { 300,300,varvSurf->w,varvSurf->h };
		SDL_FreeSurface(varvSurf);

		gubbRect.x++;

		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, bgTx, NULL, NULL);
		SDL_RenderCopy(ren, pacTx, NULL, &pacRect);
		SDL_RenderCopy(ren, gubbTx, NULL, &gubbRect);
		SDL_RenderCopy(ren, varvTx, NULL, &varvRect);
		SDL_RenderPresent(ren);
		SDL_DestroyTexture(varvTx);

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)	//ett bättre sätt att fördröja
			SDL_Delay(delay);


	}// while
	SDL_DestroyTexture(pacTx);
	Mix_FreeChunk(musik);
	TTF_CloseFont(font);
	SDL_DestroyTexture(bgTx);
	SDL_DestroyTexture(gubbTx);
	// + de andra! 

	//SDL_Delay(5000); // inte nödvändig när händelseloopen kan avsluta program

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	TTF_Quit();
	SDL_Quit();
	return 0;
};
