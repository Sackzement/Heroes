#pragma once
#include "Position.h"
#include "Size.h"
#include <SDL/SDL_rect.h>





struct Transform {
	Position pos;
	Size     size;
	double   rot;

	Transform();
	Transform(Position p, Size s, double r);

	Transform & operator<< (const Transform rhs);
	SDL_Rect toRect() const;
};