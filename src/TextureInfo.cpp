#include "TextureInfo.h"

#include "Log.h"
#include "Game.h"
#include <SDL/SDL_image.h>






// CONSTRUCTORS
TextureInfo::TextureInfo() :
	pointer (nullptr),
	name    (),
	size    ()
{
}

TextureInfo::TextureInfo(Size2i size) :
	pointer(nullptr),
	name(),
	size(size)
{
}

TextureInfo::TextureInfo(const std::string & name) :
	pointer(nullptr),
	name(name),
	size()
{
}





// SETs
void TextureInfo::setName(const std::string& name) {
	this->name = name;
}

void TextureInfo::setSize(Size2i size) {
	this->size = size;
}









// LOAD UNLOAD
bool TextureInfo::load() {

	return load(name);
}

bool TextureInfo::load(const std::string & name) {

	if (pointer) {
		Log("Load failed, unload texture first");
		return false;
	}

	// CREATE NEW FROM SIZE   (if no name set)
	if ( name == "" ) {

		if (size.w < 1 || size.h < 1) {
			Log("Cant create texture, size too small");
			return false;
		}

		SDL_Texture* createdTexture = SDL_CreateTexture(game.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);
		if (createdTexture == nullptr) { Log(SDL_GetError());  return false; }

		pointer = createdTexture;
	}


	// LOAD FROM FILE
	else {
		//check if already exists
		try {
			TextureInfo& tex = game.textures.at(name);
			*this = tex;
		}
		catch (out_of_range ex) {
			// load surface
			string str = game.path_res + name;
			SDL_Surface* loadedSurf = IMG_Load(str.c_str());
			if (loadedSurf == nullptr) { Log(SDL_GetError()); return false; }

			// create texture from surface
			SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(game.renderer, loadedSurf);
			int width = loadedSurf->w,
				height = loadedSurf->h;
			SDL_FreeSurface(loadedSurf);
			if (loadedTexture == nullptr) { Log(SDL_GetError());  return false; }

			pointer = loadedTexture;
			this->name = name;
			size.w = width;
			size.h = height;

			game.textures[name] = *this;
		}
	}


	return true;
}

void TextureInfo::unload()
{
	if (pointer == nullptr)
		Log("No texture to unload");
	else {
		SDL_DestroyTexture(pointer);
		pointer = nullptr;
	}

	size.nullify();

	// name stays the same for future loading
}




// RENDER
void TextureInfo::render(Transform offset) const {

	SDL_Rect dstRect = offset.toRect();


	SDL_RenderCopyEx(
		game.renderer, // renderer
		pointer,       //         SDL_Texture*
		nullptr,       // srcrect SDL_Rect*
		&dstRect,      //          SDL_Rect*
		offset.rot,    // angle
		nullptr,       // center  SDL_Point*
		SDL_FLIP_NONE  // filp
	);
}
