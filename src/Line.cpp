#include "Line.h"
#include "Game.h"


const double pi = 3.14159265359;


void Line::render(Transform offset) const  {

	offset << *this;

	SDL_Point a, b;
	double line_size;
	if (offset.size.w >= offset.size.h)
		line_size = offset.size.w;
	else
		line_size = offset.size.h;

	double rotX, rotY;
	rotX = cos(offset.rot*(pi/180.));
	rotY = sin(offset.rot*(pi/180.));
	a.x = int(offset.pos.x - (rotX * (line_size / 2)));
	a.y = int(offset.pos.y + (rotY * (line_size / 2)));
	b.x = int(offset.pos.x + (rotX * (line_size / 2)));
	b.y = int(offset.pos.y - (rotY * (line_size / 2)));

	a.x += game.window.w / 2;
	a.y += game.window.h / 2;
	b.x += game.window.w / 2;
	b.y += game.window.h / 2;

	SDL_RenderDrawLine(game.renderer, a.x, a.y, b.x, b.y);
}



void Line::renderStatic(Transform offset)  {

	SDL_Point a, b;
	double line_size;
	if (offset.size.w >= offset.size.h)
		line_size = offset.size.w;
	else
		line_size = offset.size.h;

	double rotX, rotY;
	rotX = cos(offset.rot*(pi/180.));
	rotY = sin(offset.rot*(pi/180.));
	a.x = int(offset.pos.x - (rotX * (line_size/2)));
	a.y = int(offset.pos.y + (rotY * (line_size/2)));
	b.x = int(offset.pos.x + (rotX * (line_size/2)));
	b.y = int(offset.pos.y - (rotY * (line_size/2)));

	a.x += game.window.w / 2;
	a.y += game.window.h / 2;
	b.x += game.window.w / 2;
	b.y += game.window.h / 2;

	SDL_RenderDrawLine(game.renderer, a.x, a.y, b.x, b.y);
}
