#include "Libs.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "Log.h"

#include <string>
using std::string;



void Libs::init() {

	if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
        Log(SDL_GetError());

    if ( IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG )
        Log(SDL_GetError());

    if ( TTF_Init() == -1 )
        Log(SDL_GetError());

}

void Libs::quit()
{
	IMG_Quit();
	SDL_Quit();
}



