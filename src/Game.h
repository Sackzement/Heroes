#pragma once
#include "Time.h"
#include "Events.h"
#include "Window.h"
#include "Keyboard.h"
#include "Mouse.h"
using namespace std;
#include "Scene.h"
#include "TextureInfo.h"
#include <functional>
#include <SDL/SDL_ttf.h>
#include "Hardware.h"

#include "Color.h" 
#include "Point.h"
#include "Line.h"
#include "Rect.h"



const double pi = 3.14159265359;



Position pixelsToScenePos(Position2i pixels);

Position pixelToScreenUnits(Position2i pixels);
Position screenUnitsToScene(Position p);
Position pixelDistToSceneDist(Position2i pixels);
Position pixelDistToScreenDist(Position2i pixels);

std::string to_string_prec(const double d, const int prec = 2);
std::string getExtension(const std::string& str);


#include <map>



struct Game {
private:
    enum class game_states {
        running,
        paused,
        quitting,
    };
public:
	// vars
	int argc;
    char** argv;
    string path;
    string path_res;

	const double 
		w = 16., 
		h = 9.;

	 Uint64 loop_counter;
	 Time time;
	 Keyboard keyboard;
	 Mouse mouse;

	 Hardware hardware;

	 Window window;
	 Renderer renderer;


	 TTF_Font* font;

	 std::map<const string, TextureInfo> textures;

	 Scene* scene;
	 game_states state;

protected:
	 vector <function<void()>> scripts;

	 void generatePath();
public:

	 // functions
	int start(int argc,char** argv);
    
	void pause();
	void unpause();
    void togglePause();
	void quit();
	void switchToScene(scene_num num);
	void addScript(function<void()>func);
    void loadCharTextures();
private:
	void mainloop();
	void exeScripts();
	void input();
	void update();
	void render();

};



extern Game game;