#pragma once
#include "Scene.h"



class Credits : virtual public Scene  {

	virtual ~Credits() {}

	void input() override;
	void render(Transform offset) const override;
};


