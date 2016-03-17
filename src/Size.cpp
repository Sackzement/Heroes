#include "Size.h"



Size::Size() :w(1.), h(1.) {}
Size::Size(double ww, double hh) :w(ww), h(hh) {}

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