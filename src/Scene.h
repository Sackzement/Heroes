#pragma once

#include "Object.h"
#include "Position2i.h"



enum struct scene_num {
	mainmenu,
	level,
	stats,
	options,
	credits,
};


struct Scene : virtual public Object {


	static double pixelToUnits(double pix);
	static Position pixelToPos(Position2i pos);


	virtual ~Scene() {}

	bool load() override;

	virtual void render(Transform offset) const override;
	using Object::render;
protected:
	void renderBG(SDL_Color col, Transform offset) const;

};


