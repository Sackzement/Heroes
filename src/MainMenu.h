#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"

class MainMenu : virtual public Scene {


public:
	MainMenu();
	virtual ~MainMenu() {}
	Player player;
	Button btn_start, btn_options, btn_quit;

	bool load() override;
	void input() override;


};