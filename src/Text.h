#pragma once
#include "Transform.h"
#include "Load.h"
#include "Render.h"

#include <SDL/SDL_ttf.h>
#include <string>
using std::string;
#include <SDL/SDL_pixels.h>
#include <SDL/SDL_render.h>




struct Text 
	: virtual public Transform, 
	  virtual public Load, 
	  virtual public Render {




	TTF_Font* font;
	string text;
	SDL_Color color;
	SDL_Texture* texture;




	Text();
	~Text();

	bool load() override;
	void render(Transform offset) const override;
	void unload() override;



	

};