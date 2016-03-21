#include "Libs.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include <iostream>
using std::cout;
using std::endl;



void Libs::init() {

	if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
		cout << endl << SDL_GetError();

	if ( IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG )
		cout << endl << SDL_GetError();

	if ( TTF_Init() == -1 )
		cout << endl << SDL_GetError();

}

void Libs::quit()
{
	IMG_Quit();
	SDL_Quit();
}



