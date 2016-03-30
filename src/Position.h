#pragma once


struct Position {
	
	double x,y,z;
	
	Position();
	virtual ~Position() {}
	Position(double x, double y);
	Position(double x, double y, double z);

	Position & operator += (const Position p);
	Position & operator *= (const double d);
	Position & operator /= (const double d);
	void set(double x, double y, double z);
	void set(double x, double y);
	void floor();

	void nullify();
	void default();
};



#include "Scale.h"
Position operator * (const Position p, const Scale s);
Position operator + (const Position p, const Scale s);