#include "Transform.h"
#include "Game.h"
#include <cmath>
#include "Collision.h"








Transform::Transform() :pos(), scale(), rot(0.) {}
Transform::Transform(Position p, Scale s, double r) :pos(p), scale(s), rot(r) {}

Transform::Transform(double xx, double yy, double zz, double ww, double hh, double rr)
	:	pos(xx,yy,zz),
	    scale(ww,hh),
		rot(rr)
{
}

void Transform::nullify()
{
	pos.nullify();
	scale.nullify();
	rot = 0.;
}

void Transform::default()
{
	pos.default();
	scale.default();
	rot = 0.;
}

void Transform::set(double xx, double yy, double zz, double ww, double hh, double rr)
{
	pos = Position(xx,yy,zz);
	scale = Scale(ww, hh);
	rot = rr;
}

Transform &Transform:: operator<< (const Transform rhs) {

	pos += rhs.pos * scale;
	scale *= rhs.scale;
	rot += rhs.rot;

	return *this;
}
Transform & Transform::operator +=(const Transform t)
{
	pos += t.pos;
	scale += t.scale;
	rot += t.rot;

	return *this;
}
SDL_Rect Transform::toRect() const
{
	Transform rect_trans = *this;
	rect_trans.pos.x -= scale.x / 2;
	rect_trans.pos.y -= scale.y / 2;

	SDL_Rect ret = {(int)rect_trans.pos.x,
					(int)rect_trans.pos.y,
		            (int)std::ceil(rect_trans.scale.x),
					(int)std::ceil(rect_trans.scale.y) };

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

Collision Transform::checkCollision(Transform other) const
{
	Collision coll;
	coll.nullify();


	if (other.right() >= this->left()
		&& other.left() <= this->right()
		&& other.bottom() >= this->top()
		&& other.top() <= this->bottom() )
	{
		// generate collision trans
		double
			top    = (other.top()    > this->top())    ? other.top()    : this->top(),
			left   = (other.left()   > this->left())   ? other.left()   : this->left(),

			bottom = (other.bottom() < this->bottom()) ? other.bottom() : this->bottom(),
			right  = (other.right()  < this->right())  ? other.right()  : this->right();

		coll.scale.set(right - left, bottom - top);
		coll.pos.set(left + (coll.scale.x * .5),
			         top  + (coll.scale.y * .5) );

		// check if touch
		if (other.right() == this->left()
			|| other.left() == this->right()
			|| other.bottom() == this->top()
			|| other.top() == this->bottom() )
			coll.type = coll_type::touch;
		else 
			coll.type = coll_type::intersect;
	}
	else
		coll.type = coll_type::none;


	return coll;
}

double Transform::top() const
{
	return pos.y - (scale.y * .5);
}

double Transform::bottom() const
{
	return pos.y + (scale.y * .5);
}

double Transform::left() const
{
	return pos.x - (scale.x * .5);
}

double Transform::right() const
{
	return pos.x + (scale.x * .5);
}

Transform operator*(const Transform t, const double d)
{
	Transform ret(t);

	ret.pos   *= d;
	ret.scale *= d;
	ret.rot   *= d;

	return ret;
}
