#include <SDL/SDL_platform.h>
#include "Game.h"



#if defined(__WINDOWS__) && (_WINDOWS)
int WinMain
#else
int main
#endif

(int argc, char** argv) {


	game.start();
	return 0;
}

