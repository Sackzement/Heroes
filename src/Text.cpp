#include "Text.h"
#include <iostream>
using std::cout;  using std::endl;
#include "Game.h"




Text::Text() :
	font(nullptr),
	text("XXX"),
	color({0xff,0xff,0xff,0xff}),
	texture(nullptr)
{}


Text::~Text() {

}





bool Text::load() {

	if (texture)
		SDL_DestroyTexture(texture);

	if (font == nullptr)  font = game.font;

	SDL_Surface* surf = TTF_RenderText_Solid(
		font,
		text.c_str(),
		color);
	if (surf == nullptr) { cout << endl << SDL_GetError();  return false; }

	texture = SDL_CreateTextureFromSurface(game.renderer, surf);
	SDL_FreeSurface(surf);
	if (texture == nullptr) { cout << endl << SDL_GetError();  return false; }


	return true;
}


void Text::render(Transform offset) const {

	offset << *this;

	SDL_Rect dstRect = offset.toWindowRect();

	SDL_RenderCopyEx(
		game.renderer, // renderer
		texture,       //         SDL_Texture*
		nullptr,       // srcrect SDL_Rect*
		&dstRect,      //          SDL_Rect*
		offset.rot,    // angle
		nullptr,       // center  SDL_Point*
		SDL_FLIP_NONE  // filp
		);
}


void Text::unload() {
	SDL_DestroyTexture(texture);
}