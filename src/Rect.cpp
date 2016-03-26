#include "Rect.h"
#include "Game.h"




void Rect::render(Transform offset) const  {

	offset << *this;

	SDL_Rect rect = offset.toRect();
	SDL_RenderFillRect(game.renderer, &rect);
}




void Rect::renderStatic(Transform offset)  {

	SDL_Rect rect = offset.toRect();
	SDL_RenderFillRect(game.renderer, &rect);
}
