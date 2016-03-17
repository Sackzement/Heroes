#include "Transform.h"









Transform::Transform() :pos(), size(), rot(0.) {}
Transform::Transform(Position p, Size s, double r) :pos(p), size(s), rot(r) {}

Transform &Transform:: operator<< (const Transform rhs) {

	pos += rhs.pos * size;
	size *= rhs.size;
	rot += rhs.rot;

	return *this;
}
SDL_Rect Transform::toRect() const
{
	SDL_Rect ret = { static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		static_cast<int>(size.w),
		static_cast<int>(size.h) };

	return ret;
}



