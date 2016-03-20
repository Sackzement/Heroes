#pragma once
#include "Scene.h"



struct Map : virtual public Object {
	Map();
	~Map() {}

	void render(Transform offset) const override;
};

struct Level : virtual public Scene {

	Level();
	virtual ~Level() {}

	void input() override;


	Map map;
};