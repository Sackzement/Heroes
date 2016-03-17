#include "Libs.h"

#include <SDL/SDL.h>



void Libs::init() {

	SDL_Init(SDL_INIT_EVERYTHING);
}

void Libs::quit()
{
	SDL_Quit();
}



