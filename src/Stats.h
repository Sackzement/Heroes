#pragma once
#include "Scene.h"



struct Stats : virtual public Scene {

	Stats();
	virtual ~Stats() {}

	void input() override;
	void render(Transform offset) const override;
};