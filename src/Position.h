#pragma once


struct Position {
	
	double x,y,z;
	
	Position();
	Position(double xx, double yy);
	Position(double xx, double yy, double zz);

	Position & operator += (const Position rhs);
};



#include "Size.h"
Position operator * (const Position lhs, const Size rhs);