#pragma once
#include "Scene.h"
#include "Player.h"



struct Color {
	Uint8 r, g, b, a;
};

struct Level : virtual public Scene {

	// BG
	vector<Object*> bg_clouds;
	vector<Object*> bg_structures;
	Object          bg_fence;
	vector<Object*> wall_backgrounds; // steltzen / hängeseile / feuerstelle-bg
	vector<Object*> walls;

	// ForeGround
	vector<Object*> crates;
	vector<Object*> enemies;
	Player          player; // + weapon
	vector<Object*> bullets;




	// functions
	Level();
	virtual ~Level() {}

	void input() override;
	void update() override;
	void render() const override;

protected:
	void renderBG() const;
	bool init_bg_clouds();
	bool init_bg_structures();
	bool init_bg_walls();


};