#include "Point.h"
#include "Game.h"


void Point::render(Transform offset) const {
	offset << *this;
	SDL_RenderDrawPoint(game.renderer, (int)offset.pos.x, (int)offset.pos.y);
}