#include "Position.h"
#include <cmath>




Position::Position() :x(0.), y(0.), z(0.) {}
Position::Position(double x, double y) :x(x), y(y), z(0.) {}
Position::Position(double x, double y, double z) :x(x), y(y), z(z) {}

Position & Position::operator += (const Position p) {

	x += p.x;
	y += p.y;
	z += p.z;

	return *this;
}

Position & Position::operator*=(const double d)
{
	x *= d;
	y *= d;
	z *= d;

	return *this;
}

Position & Position::operator/=(const double d)
{
	x /= d;
	y /= d;
	z /= d;

	return *this;
}

void Position::set(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Position::set(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Position::floor()  {

	x = std::floor(x);
	y = std::floor(y);
	z = std::floor(z);
}

void Position::nullify()
{
	x = 0;
	y = 0;
	z = 0;
}

void Position::default()
{
	nullify();
}




Position operator * (const Position pos, const Scale s) {

	Position ret(pos);

	ret.x *= s.x;
	ret.y *= s.y;

	return ret;
}

Position operator+(const Position pos, const Scale s)
{
	Position ret(pos);

	ret.x += s.x;
	ret.y += s.y;

	return ret;
}
