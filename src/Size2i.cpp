#include "Size2i.h"



Size2i::Size2i()
	: w(0), h(0)
{
}
Size2i::Size2i(int w, int h)
	: w(w), h(h)
{
}


void Size2i::set(int w, int h)
{
	this->w = w;
	this->h = h;
}
void Size2i::nullify()
{
	w = 0;
	h = 0;
}
