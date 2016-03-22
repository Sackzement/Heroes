#pragma once
#include "Transform.h"
#include "Render.h"



struct Rect : virtual public Transform, virtual public Render  {
	virtual ~Rect() {}
	void render(Transform offset) const override;
	static void renderStatic(Transform offset);
};