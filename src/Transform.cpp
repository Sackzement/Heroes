#include "Transform.h"
#include <cmath>








Transform::Transform() :pos(), size(), rot(0.) {}
Transform::Transform(Position p, Size s, double r) :pos(p), size(s), rot(r) {}

Transform::Transform(double xx, double yy, double zz, double ww, double hh, double rr)
	:	pos(xx,yy,zz),
		size(ww,hh),
		rot(rr)
{
}

void Transform::set(double xx, double yy, double zz, double ww, double hh, double rr)
{
	pos = Position(xx,yy,zz);
	size = Size(ww, hh);
	rot = rr;
}

Transform &Transform:: operator<< (const Transform rhs) {

	pos += rhs.pos * size;
	size *= rhs.size;
	rot += rhs.rot;

	return *this;
}
SDL_Rect Transform::toRect() const
{
	SDL_Rect ret = { (int)pos.x, (int)pos.y,
		             (int)std::ceil(size.w),(int)std::ceil(size.h) };

	return ret;
}

SDL_bool Transform::checkCollision(Transform other)
{
	SDL_Rect rectA = toRect();
	SDL_Rect rectB = other.toRect();
	return SDL_HasIntersection(&rectA,&rectB);
}



