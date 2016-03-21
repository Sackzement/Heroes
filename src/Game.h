#pragma once
#include "Time.h"
#include "Events.h"
#include "Window.h"
#include "Keyboard.h"
#include "Mouse.h"
using namespace std;
#include "Scene.h"
#include "Texture.h"
#include <functional>
#include <SDL/SDL_ttf.h>




#include <map>
struct Game {

protected:
	enum class game_state {
		running,
		paused,
		quitting,
	};

public:
	// vars
	int argc;
	char** argv;
	string path;

	const double 
		w = 16., 
		h = 9.;

	 Uint64 loop_counter;
	 Time time;
	 Keyboard keyboard;
	 Mouse mouse;

	 Window window;
	 Renderer renderer;

	 TTF_Font* font;

	 std::map<const string,Texture> textures;

	 Scene* scene;
	 game_state state;

protected:
	 vector <function<void()>> scripts;

	 void generatePath();
public:

	 // functions
	int start(int argc,char** argv);
	void pause();
	void unpause();
	void quit();
	void switchToScene(scene_num num);
	void addScript(function<void()>func);
private:
	void mainloop();
	void exeScripts();
	void input();
	void update();
	void render();

};



extern Game game;