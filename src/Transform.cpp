#include "Transform.h"
#include "Game.h"
#include <cmath>








Transform::Transform() :pos(), size(), rot(0.) {}
Transform::Transform(Position p, Size s, double r) :pos(p), size(s), rot(r) {}

Transform::Transform(double xx, double yy, double zz, double ww, double hh, double rr)
	:	pos(xx,yy,zz),
		size(ww,hh),
		rot(rr)
{
}

void Transform::nullify()
{
	pos.set(0., 0., 0.);
	size.nullify();
	rot = 0.;
}

void Transform::default()
{
	pos.set(0., 0., 0.);
	size.set(1., 1.);
	rot = 0.;
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
	Transform rect_trans = *this;
	rect_trans.pos.x -= size.w / 2;
	rect_trans.pos.y -= size.h / 2;

	SDL_Rect ret = {(int)rect_trans.pos.x,
					(int)rect_trans.pos.y,
		            (int)std::ceil(rect_trans.size.w),
					(int)std::ceil(rect_trans.size.h) };

	return ret;
}
/*SDL_Rect Transform::toWindowRect() const
{
	Transform trans = *this;

	trans.pos.x += (game.w / 2.) - (trans.size.w / 2.);
	trans.pos.y += (game.h / 2.) - (trans.size.h / 2.);

	trans.pos  *= Scene::getScale();
	trans.size *= Scene::getScale();

	return trans.toRect();
}*/

bool Transform::checkCollision(Transform other)
{
	double other_right = other.pos.x + (other.size.w * .5);
	double other_left  = other.pos.x - (other.size.w * .5);
	double other_up    = other.pos.y - (other.size.h * .5);
	double other_down  = other.pos.y + (other.size.h * .5);

	double this_right  = pos.x + (size.w * .5);
	double this_left   = pos.x - (size.w * .5);
	double this_up     = pos.y - (size.h * .5);
	double this_down   = pos.y + (size.h * .5);

	if (other_right >= this_left
		&& other_left <= this_right
		&& other_down >= this_up
		&& other_up <= this_down)
		return true;
	else
		return false;

}


