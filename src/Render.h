#pragma once
#include "Transform.h"

struct Render {
	virtual void render(Transform offset) const = 0;
};
