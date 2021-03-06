#pragma once
#include "Scene.h"
#include "Player.h"
#include "Key.h"

struct Controls {
    Key pause;
    Controls();
};
extern Controls controls;

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

	// selection
	Transform* selected = nullptr;



	// functions
	Level();
	virtual ~Level() {}

	bool load() override;
	void input() override;
	void update() override;
	void checkCollision();
	void render(Transform offset) const override;




protected:
	bool init_bg_clouds();
	bool init_bg_structures();
	bool init_bg_walls();


};