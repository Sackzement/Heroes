#pragma once
#include <SDL/SDL_video.h>

enum Fullscreen {
	off = 0,
	normal = 0x0001,
	fake = ( 0x1000 | normal),
	window = 0x0010,
};