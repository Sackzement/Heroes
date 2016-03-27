#include "Position.h"
#include <cmath>




Position::Position() :x(0.), y(0.), z(0.) {}
Position::Position(double xx, double yy) :x(xx), y(yy), z(0.) {}
Position::Position(double xx, double yy, double zz) :x(xx), y(yy), z(zz) {}

Position & Position::operator += (const Position rhs) {

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

Position & Position::operator*=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;
}

Position & Position::operator/=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;

	return *this;
}

void Position::set(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
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




Position operator * (const Position lhs, const Size rhs) {

	Position ret(lhs);

	ret.x *= rhs.w;
	ret.y *= rhs.h;

	return ret;
}

Position operator+(const Position lhs, const Size rhs)
{
	Position ret(lhs);

	ret.x += rhs.w;
	ret.y += rhs.h;

	return ret;
}
