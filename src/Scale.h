#pragma once


struct Scale {
	
	double x,y;
	
	Scale();
	Scale(double x, double y);

	void default();
	void nullify();

	Scale & operator *= (const Scale s);
	Scale & operator *= (const double d);
	Scale & operator += (const double d);
	Scale & operator += (const Scale s);
	

	Scale & operator = (const double d);
	void set(double w, double h);

	void ceil();
};


