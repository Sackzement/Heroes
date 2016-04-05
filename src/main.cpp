#include <SDL/SDL_platform.h>
#include "Game.h"
#include "Log.h"


#if defined(__WINDOWS__) && (_WINDOWS)
int WinMain
#else
int main
#endif

(int argc, char** argv) {
    
    Log(argv[0]);
	
    return game.start(argc,argv);
}

