#pragma once
#include "Transform.h"
#include "Load.h"
#include "Render.h"
#include <SDL/SDL_render.h>









struct Texture :virtual public Transform, virtual public Load, virtual public Render{

	SDL_Texture*  texture = nullptr;
	const char* name = "";


	Texture();
	Texture(int w, int h);
	Texture(const char* name);
	virtual ~Texture() {}

	operator SDL_Texture* ();

	        bool load() override;
	virtual bool load(const char* name);
	void unload() override;
	void render(Transform offset) const override;

};





