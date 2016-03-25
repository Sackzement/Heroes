#include "Line.h"
#include "Game.h"


const double pi = 3.14159265359;


void Line::render(Transform offset) const  {

	offset << *this;
	offset.size *= Scene::getScale();

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

	 // transforms for points
	 Transform trans_a, trans_b;
	 trans_a.nullify();
	 trans_b.nullify();

	 // place
	 trans_a.pos = offset.pos;
	 trans_b.pos = offset.pos + offset.size;


	 // rotate
	double cos_rot, sin_rot;
	cos_rot = cos(offset.rot*(pi/180.));
	sin_rot = sin(offset.rot*(pi/180.));

	Transform old_a = trans_a, old_b = trans_b;
	trans_a.pos.x = (cos_rot*old_a.pos.x) + (sin_rot*old_a.pos.y);
	trans_a.pos.y = (cos_rot*old_a.pos.y) + (sin_rot*old_a.pos.x);
	trans_b.pos.x = (cos_rot*old_b.pos.x) + (sin_rot*old_b.pos.y);
	trans_b.pos.y = (cos_rot*old_b.pos.y) + (sin_rot*old_b.pos.x);



	// transfer to window coords
	SDL_Rect rectA = trans_a.toWindowRect();
	SDL_Rect rectB = trans_b.toWindowRect();

	// draw
	SDL_RenderDrawLine(game.renderer, rectA.x, rectA.y, rectB.x, rectB.y);
}
