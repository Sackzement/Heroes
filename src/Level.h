#pragma once
#include "Scene.h"
#include "Player.h"




struct Level : virtual public Scene {

	Player player;
	vector<Object*> walls;

	Level();
	virtual ~Level() {}

	void input() override;
	void render() const override;


};