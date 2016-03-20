#pragma once
#include "Scene.h"
#include "Button.h"




struct Options : virtual public Scene {

	Button btn_back;


	Options();
	virtual ~Options() {}
};