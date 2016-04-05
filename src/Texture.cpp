#include "Texture.h"
#include <SDL/SDL_image.h>
#include "game.h"

#include <iostream>
using std::cout;
using std::endl;



Texture::Texture() 
	:texture(nullptr),
	 name("")
{}
Texture::Texture(int w, int h)
	: texture(nullptr),
	name("")
{
	scale.x = w;
	scale.y = h;
}
Texture::Texture(const char* name)
	: texture(nullptr),
	name(name)
{}




Texture:: operator SDL_Texture* () {
	return texture;
}




bool Texture::load() {

	return load(name);
}



bool Texture:: load (const char* name) {

	// CREATE NEW FROM SIZE
	if (name == "") {
		if ( scale.x < 1 || scale.y < 1 )   {
			cout << endl << "Texture Size too small";
			return false;
		}

    SDL_Texture* createdTexture=SDL_CreateTexture(game.renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,(int)scale.x,(int)scale.y);
		if (createdTexture == nullptr) { cout << endl << SDL_GetError();  return false; }

		texture = createdTexture;
	}
	// LOAD FROM FILE
	else {
		//check if already exists
		try {
			Texture& tex = game.textures.at(name);
			*this = tex;
		}
		catch (out_of_range ex) {
			// load surface
			string str = game.path + name;
			SDL_Surface* loadedSurf = IMG_Load(str.c_str());
			if (loadedSurf == nullptr) { cout << endl << SDL_GetError(); return false; }
			
			// create texture from surface
			SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(game.renderer, loadedSurf);
			int width = loadedSurf->w,
				height = loadedSurf->h;
			SDL_FreeSurface(loadedSurf);
			if (loadedTexture == nullptr) { cout << endl << SDL_GetError();  return false; }

			texture = loadedTexture;
			this->name = name;
			scale.x = width;
			scale.y = height;

			game.textures[name] = *this;
		}
	}


	return true;
}
 

void Texture::unload() {

	texture = nullptr;

	name = "";
	Transform::Transform();

}


void Texture::render(Transform offset) const {

	SDL_Rect dstRect = offset.toRect();


	
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










