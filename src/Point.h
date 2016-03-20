#pragma once
#include "Transform.h"
#include "Render.h"





struct Point : virtual public Transform, virtual public Render {
	virtual ~Point() {}
	void render(Transform offset) const override;
};