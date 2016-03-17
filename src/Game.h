#pragma once
#include "Time.h"
#include "Events.h"
#include "Window.h"
#include "Keyboard.h"
using namespace std;
#include "Scene.h"
#include "Texture.h"



#include <map>
struct Game {
	// vars
	const double 
		w = 16., 
		h = 9.;

	 Uint64 loop_counter;
	 Time time;
	 Keyboard keyboard;
	 Window window;
	 Renderer renderer;

	 std::map<const char*,Texture> textures;

	 Scene* scene;
	 bool quit;

	 // functions
	void start();
private:
	void mainloop();
	void input();
	void update();
	void render();

};



extern Game game;