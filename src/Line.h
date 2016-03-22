#pragma once
#include "Transform.h"
#include "Render.h"




struct Line : virtual public Transform, virtual public Render {
	virtual ~Line() {}
	void render(Transform offset) const override;
	static void renderStatic(Transform offset);
};

