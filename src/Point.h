#pragma once
#include "Transform.h"
#include "Render.h"





struct Point : virtual public Transform, virtual public Render {
	void render(Transform offset) const override;
};