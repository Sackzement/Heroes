#pragma once

#include "Object.h"



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

	virtual void render() const;
	using Object::render;

};


