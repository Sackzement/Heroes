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

	Scene();
	virtual ~Scene() {}

	void rescale();
	bool load() override;
	double pixelToUnits(double pix);
	Position pixelToPos(Position2i pos);

	virtual void render() const;
	using Object::render;

};


