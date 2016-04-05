#include "Rect.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;




void Rect::render(Transform offset) const  {

	offset << *this;

	SDL_Rect rect = offset.toRect();
	SDL_RenderFillRect(game.renderer, &rect);
}




void Rect::renderStatic(Transform offset)  {


	if (offset.scale.x < 1 || offset.scale.y < 1) {
		cout << endl << "Texture Size too small";
		return;
	}

	SDL_Texture* createdTexture = SDL_CreateTexture(game.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)offset.scale.x, (int)offset.scale.y);
	if (createdTexture == nullptr) { cout << endl << SDL_GetError();  return ; }

	// colorize texture
	game.renderer.setTarget(createdTexture);
	game.renderer.clear();
	game.renderer.setTarget(nullptr);

	// draw
	SDL_Rect dstRect = offset.toRect();

	SDL_RenderCopyEx(
		game.renderer, // renderer
		createdTexture,       //         SDL_Texture*
		nullptr,       // srcrect SDL_Rect*
		&dstRect,      //          SDL_Rect*
		offset.rot,    // angle
		nullptr,       // center  SDL_Point*
		SDL_FLIP_NONE  // filp
		);

	SDL_DestroyTexture(createdTexture);
}
