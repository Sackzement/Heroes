#include "Texture.h"
#include <SDL/SDL_image.h>
#include "game.h"
#include <iostream>


Texture::Texture() 
	:texture(nullptr),
	 name(""),
	 w(0),
	 h(0)
{}



Texture:: operator SDL_Texture* () {
	return texture;
}




bool Texture::load() {
	return false;
}
bool Texture:: load (const char* name) {

		// load surface
		SDL_Surface* loadedSurf = IMG_Load(name);
		if (loadedSurf == nullptr) { cout << endl << SDL_GetError(); return false; }

		

		// create texture from surface
		texture = SDL_CreateTextureFromSurface(game.renderer, loadedSurf);
		int width = loadedSurf->w,
			height = loadedSurf->h;
		SDL_FreeSurface(loadedSurf);

		if (texture == nullptr) { cout << endl << SDL_GetError();  return false; }

		this->texture  = texture;
		this->name     = name;
		this->w        = width;
		this->h        = height;

		return true;
}
 

void Texture::unload() {

	SDL_DestroyTexture(texture);
	texture = nullptr;

	name = "";
	w = h = 0;

}


void Texture::render(Transform offset) const {

	offset << *this;

	SDL_Rect dstRect = offset.toRect();

	dstRect.w *= w;
	dstRect.h *= h;


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










