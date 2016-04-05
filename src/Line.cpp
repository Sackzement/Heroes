#include "Line.h"
#include "Game.h"




void Line::render(Transform offset) const  {

	offset << *this;

	renderStatic(offset);
}






 void Line::renderStatic(Transform offset)  {

	 // transforms for points
	 Transform trans_a, trans_b;
	 trans_a.nullify();
	 trans_b.nullify();

	 // place
	 trans_a.pos = offset.pos;
	 trans_b.pos = offset.pos + offset.scale;


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
	SDL_Rect rectA = trans_a.toRect();
	SDL_Rect rectB = trans_b.toRect();

	// draw
	SDL_RenderDrawLine(game.renderer, rectA.x, rectA.y, rectB.x, rectB.y);
}
