#pragma once

#include "Object.h"



enum struct scene_num {
	mainmenu,
	options,
	level
};


struct Scene : virtual public Object {

	Scene();
	virtual ~Scene() {}

	void rescale();
	bool load() override;
	double pixelToUnits(double pix);

	void render() const;
	using Object::render;

};


