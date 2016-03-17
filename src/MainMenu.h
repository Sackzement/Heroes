#pragma once
#include "Scene.h"

class MainMenu : virtual public Scene {


public:
	MainMenu();

	bool load() override;
protected:
	bool loadButtons();

};