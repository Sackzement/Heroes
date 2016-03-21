#pragma once
#include "Scene.h"
#include "Player.h"



struct Walls : virtual public Object {

	Walls();
	~Walls() {}

	void render(Transform offset) const override;
};





struct Level : virtual public Scene {

	Player player;
	Walls walls;

	Level();
	virtual ~Level() {}

	void input() override;
	void render() const override;


};