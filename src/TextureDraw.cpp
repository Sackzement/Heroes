#include "TextureDraw.h"

#include "TextureInfo.h"
#include "Game.h"
#include "Log.h"



TextureDraw::TextureDraw() :
	name(),
	pTex(nullptr)
{
}

TextureDraw::TextureDraw(const std::string & name) :
	name(name),
	pTex(nullptr)
{
}






void TextureDraw::setName(const std::string & name) {
	this->name = name;
}







bool TextureDraw::load() {

	return load(name);
}

bool TextureDraw::load(const std::string & name) {

	try {
		TextureInfo& tex = game.textures.at(name);

		pTex = tex.getPointer();

		return true;
	}
	catch (out_of_range ex) {

		Log("Can not find texture \"" + name + "\". Load it first as TextureInfo");
		return false;
	}

}

void TextureDraw::unload() {

	pTex = nullptr;
}





void TextureDraw::render(Transform offset) const {

	offset << *this;

	SDL_Rect dstRect = offset.toRect();


	SDL_RenderCopyEx(
		game.renderer, // renderer
		pTex,          //         SDL_Texture*
		nullptr,       // srcrect SDL_Rect*
		&dstRect,      //          SDL_Rect*
		offset.rot,    // angle
		nullptr,       // center  SDL_Point*
		SDL_FLIP_NONE  // filp
	);
}
