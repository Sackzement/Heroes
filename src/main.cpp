#include <SDL/SDL_platform.h>
#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;


#if defined(__WINDOWS__) && (_WINDOWS)
int WinMain
#else
int main
#endif

(int argc, char** argv) {
	cout << endl << argv[0];
	return game.start(argc,argv);
}

