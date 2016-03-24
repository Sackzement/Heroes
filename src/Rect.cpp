#include "Rect.h"
#include "Game.h"




void Rect::render(Transform offset) const  {

	offset << *this;

	SDL_Rect rect = offset.toRect();

	rect.x += (game.window.w / 2) - (rect.w / 2);
	rect.y += (game.window.h / 2) - (rect.h / 2);

	SDL_RenderFillRect(game.renderer, &rect);
}




void Rect::renderStatic(Transform offset)  {

	SDL_Rect rect = offset.toWindowRect();

	SDL_RenderFillRect(game.renderer, &rect);
}
