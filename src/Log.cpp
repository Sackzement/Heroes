#include "Log.h"
#include <iostream>
#include <SDL/SDL_rwops.h>


void Log(const std::string & str) {
    
	size_t len = str.length();
	if (len == 0)
		return;

	SDL_RWops*  rw = SDL_RWFromFile("log.txt", "a");
    if (rw) {
        // write new line //+ time
        SDL_RWwrite(rw, "\n", 1, 1);
        // write string
        SDL_RWwrite(rw, str.c_str(), 1, len);
		SDL_RWclose(rw);
	}

	std::cout << "\n" << str;
}