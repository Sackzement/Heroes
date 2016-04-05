#pragma once
#include "Position.h"
#include "Scale.h"
#include <SDL/SDL_rect.h>
#include "Nullify.h"
#include "Render.h"

struct Collision;








struct Transform : virtual public Nullify, virtual public Render {




	Position pos;
	Scale    scale;
	double   rot;




	Transform();
	Transform(Position p, Scale s, double r);
	Transform(double x, double y, double z, double w, double h, double r);
	Transform(double x, double y, double z, double w, double h);

	virtual ~Transform() {}

	void nullify() override;
	void default();

	void set(double xx, double yy, double zz, double ww, double hh, double rr);

	Transform & operator<< (const Transform rhs);
	Transform & operator+= (const Transform t);



	SDL_Rect toRect() const;
	//SDL_Rect toWindowRect() const;
	Collision checkCollision(Transform other) const;

	double top() const;
	double bottom() const;
	double left() const;
	double right() const;



	void render(Transform offset) const override;

};





Transform operator * (const Transform t, const double d);