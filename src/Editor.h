#pragma once

#include "Input.h"
#include "Render.h"



struct Editor :
	virtual public Input,
	virtual public Render
{

	bool visible;

	Editor();
	virtual ~Editor() {}

	void input() override;
	void render(Transform offset) const override;
};