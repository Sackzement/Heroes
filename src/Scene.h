#pragma once

#include "Object.h"




struct Scene : virtual public Object {

	void rescale();
	void render() const;
	using Object::render;

};


