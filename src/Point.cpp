#include "Point.h"
#include "Game.h"




void Point::render(Transform offset) const {
	offset << *this;
	renderStatic(offset);
}



void Point::renderStatic(Transform offset)
{
	offset.scale.nullify();
	SDL_Rect rect = offset.toRect();


	SDL_RenderDrawPoint(game.renderer, rect.x, rect.y);
}
