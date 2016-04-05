#pragma once

struct Position2i;
struct Scale;



struct Position {
	
	double x,y,z;
	
	Position();
	virtual ~Position() {}
	Position(double x, double y);
	Position(double x, double y, double z);
	Position(Position2i pos2i);

	Position & operator += (const Position p);
	Position & operator -= (const Position p);

	Position & operator *= (const double d);
	Position & operator /= (const double d);

	Position & operator *= (const Scale s);
	Position & operator /= (const Scale s);

	void set(double x, double y, double z);
	void set(double x, double y);
	void floor();
	void nullify();
	void defaultify();
};




Position operator + (const Position p, const Position p2);
Position operator - (const Position p, const Position p2);

Position operator + (const Position p, const Scale s);
Position operator - (const Position p, const Scale s);
Position operator * (const Position p, const Scale s);
Position operator / (const Position p, const Scale s);

Position operator*  (const Position p, const double d);
