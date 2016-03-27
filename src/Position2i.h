#pragma once
#include "Transform.h"


struct Position2i {
	int x = 0, y = 0;

	operator Transform () {

		Transform ret;  ret.nullify();

		ret.pos.x = double(x);
		ret.pos.y = double(y);
		ret.pos.z = 0.;

		return ret;
	}
};