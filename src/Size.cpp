#include "Size.h"

#include <cmath>



Size::Size() :w(1.), h(1.) {}
Size::Size(double ww, double hh) :w(ww), h(hh) {}

void Size::nullify()
{
	w = 0.;
	h = 0.;
}

Size & Size::operator *= (const Size rhs) {

	w *= rhs.w;
	h *= rhs.h;

	return *this;
}
Size & Size::operator *= (const double rhs) {

	w *= rhs;
	h *= rhs;

	return *this;
}
Size & Size::operator = (const double rhs) {

	w = rhs;
	h = rhs;

	return *this;
}

void Size::set(double w, double h)
{
	this->w = w;
	this->h = h;
}

void Size::ceil()  {

	w = std::ceil(w);
	h = std::ceil(h);
}
