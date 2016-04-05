#pragma once

#include "Scene.h"











struct LevelEditor :	virtual public Scene
{


	LevelEditor();
	virtual ~LevelEditor() {}



	void input() override;
	void render(Transform offset) const override;


	// selection
	vector<Transform*> selection;
};

