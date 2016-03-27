#pragma once
#include "Transform.h"

struct Render : virtual public Transform{
	virtual ~Render() {}
	virtual void render(Transform offset) const = 0;
};
