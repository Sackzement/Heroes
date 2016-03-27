#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
#include "Text.h"

class MainMenu : virtual public Scene {


public:

	Text title,
		startgame, stats, options, credits, quit;
	Uint8 selection;






	MainMenu();
	virtual ~MainMenu() {}


	bool load() override;
	void input() override;
	void update() override;
	void render(Transform offset) const override;



protected:


};