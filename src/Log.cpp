#include "Log.h"
#include <iostream>
#include <SDL/SDL_rwops.h>


void Log(const std::string & str) {

	size_t len = str.length();
	if (len == 0)
		return;

	SDL_RWops*  rw = SDL_RWFromFile("log.txt", "a");
	if (rw) {
		if (len != SDL_RWwrite(rw, str.c_str(), 1, len))
			std::cout << str;
		SDL_RWclose(rw);
	}

	std::cout << str;
}