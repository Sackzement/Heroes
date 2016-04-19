#pragma once

#include "Transform.h"
#include "Load.h"
#include "Render.h"
#include <SDL/SDL_render.h>

#include <string>



class TextureDraw : virtual public Transform, virtual public Load, virtual public Render {

	std::string   name;
	SDL_Texture*  pTex;


public:
	TextureDraw();
	TextureDraw(const std::string& name);
	virtual ~TextureDraw() {}



	inline SDL_Texture* getTexture() const {
		return pTex;
	}
	inline const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name);



	bool load() override;
	virtual bool load(const std::string& name);

	// loads textureinfo if there is none
	bool loadForce();
	// loads textureinfo if there is none
	bool loadForce(std::string& name);
	void unload() override;
	void render(Transform offset) const override;
};