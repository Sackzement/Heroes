#include "Point.h"
#include "Game.h"


void Point::render(Transform offset) const {
	offset << *this;
	SDL_Rect rect = offset.toRect();

	rect.x += (game.window.w / 2);
	rect.y += (game.window.h / 2);

	SDL_RenderDrawPoint(game.renderer, rect.x, rect.y);
}

void Point::renderStatic(Transform offset)
{
	SDL_Rect rect = offset.toRect();

	rect.x += (game.window.w / 2);
	rect.y += (game.window.h / 2);

	SDL_RenderDrawPoint(game.renderer, rect.x, rect.y);
}
