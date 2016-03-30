#pragma once
#include "Transform.h"


struct Position2i {

	int  x, y;



	Position2i()              :  x(0), y(0)  {}
	Position2i(int x, int y)  :  x(x), y(y)  {}

	void set(int x, int y) {

		this->x = x;
		this->y = y;
	}
	void nullify()
	{
		x = 0;
		y = 0;
	}

	Transform to_Transform() {

		Transform ret;  ret.nullify(); // why null?

		ret.pos.x = double(x);
		ret.pos.y = double(y);
		ret.pos.z = 0.;

		return ret;
	}
};