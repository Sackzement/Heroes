#include "Scale.h"

#include <cmath>



Scale::Scale() 
	:x(1.), y(1.)
{
}
Scale::Scale(double x, double y) :x(x), y(y)
{
}


void Scale::default()
{
	x = 1.;
	y = 1.;
}
void Scale::nullify()
{
	x = 0.;
	y = 0.;
}

Scale & Scale::operator *= (const Scale s) {

	x *= s.x;
	y *= s.y;

	return *this;
}
Scale & Scale::operator *= (const double d) {

	x *= d;
	y *= d;

	return *this;
}
Scale & Scale::operator+=(const double d)
{
	x += d;
	y += d;

	return *this;
}
Scale & Scale::operator+=(const Scale s)
{
	x += s.x;
	y += s.y;

	return *this;
}


Scale & Scale::operator = (const double d) {

	x = d;
	y = d;

	return *this;
}

void Scale::set(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Scale::ceil()  {

	x = std::ceil(x);
	y = std::ceil(y);
}
