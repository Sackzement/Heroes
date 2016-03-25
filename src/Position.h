#pragma once


struct Position {
	
	double x,y,z;
	
	Position();
	virtual ~Position() {}
	Position(double xx, double yy);
	Position(double xx, double yy, double zz);

	Position & operator += (const Position rhs);
	Position & operator *= (const double rhs);
	void set(double xx, double yy, double zz);
	void floor();
};



#include "Size.h"
Position operator * (const Position lhs, const Size rhs);
Position operator + (const Position lhs, const Size rhs);