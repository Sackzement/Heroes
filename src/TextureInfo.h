#pragma once

#include "Load.h"
#include "Render.h"

#include <SDL/SDL_render.h> // SDL_Texture
#include <string>           // name
#include "Size2i.h"         // size

#include "Transform.h"









class TextureInfo : virtual public Load, virtual public Render {

	SDL_Texture*  pointer;
	std::string   name;
	Size2i        size;


public:
	TextureInfo();
	TextureInfo(Size2i size);
	TextureInfo(const std::string& name);
	virtual ~TextureInfo() {}

	inline SDL_Texture* getPointer() const {
		return pointer;
	}
	inline const std::string& getName() const {
		return name;
	}
	inline Size2i getSize() const {
		return size;
	}

	void setName(const std::string& name);
	void setSize(Size2i size);



	bool load() override;
	virtual bool load(const std::string& name);
	void unload() override;
	void render(Transform offset) const override;

};
