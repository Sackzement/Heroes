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
	Transform(double xx, double yy, double zz, double ww, double hh, double rr);
	virtual ~Transform() {}

	void set(double xx, double yy, double zz, double ww, double hh, double rr);

	Transform & operator<< (const Transform rhs);
	SDL_Rect toRect() const;

	SDL_bool checkCollision(Transform other);

};