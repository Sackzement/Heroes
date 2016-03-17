#pragma once


struct Size {
	
	double w,h;
	
	Size();
	Size(double ww, double hh);

	Size & operator *= (const Size rhs);
	Size & operator *= (const double rhs);
	Size & operator = (const double rhs);
};


