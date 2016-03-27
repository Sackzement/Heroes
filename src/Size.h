#pragma once


struct Size {
	
	double w,h;
	
	Size();
	Size(double ww, double hh);
	virtual ~Size() {}

	void nullify();

	Size & operator *= (const Size rhs);
	Size & operator *= (const double rhs);
	Size & operator += (const double rhs);

	Size & operator = (const double rhs);
	void set(double w, double h);

	void ceil();
};


