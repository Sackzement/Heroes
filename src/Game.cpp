#include "Game.h"
#include "Libs.h"
#include "MainMenu.h"
#include "Level.h"
#include "Stats.h"
#include "Options.h"
#include "Credits.h"
#include "Color.h"
//#include "HardwareInfo.h"

#include "Scene.h"




Game game;


const char * filename_font_file = "res\\Zillah Modern Expanded.ttf";
const int font_size = 128;





void Game::generatePath() {
	string str = string(argv[0]);
	size_t len = str.size();
	for (size_t i = len - 1; i >= 0;--i) {
		if (str[i] == '\\')  break;
		else str.pop_back();
	}
	path = str;
}

int Game::start(int argc, char** argv) {
	this->argc = argc;
	this->argv = argv;
	// generate path
	generatePath();

	Libs::init();
	hardware.update();
	window.create();
	renderer.create();

	// load font
	string str = path + filename_font_file;
	font = TTF_OpenFont(str.c_str(), font_size);


	scene = new MainMenu();
	scene->load();


	time.resetDelay();

	

	mainloop();

	renderer.destroy();
	window.destroy();
	Libs::quit();

	return 0;
}

void Game::pause() {
	state = game_state::paused;
}
void Game::unpause() {
	state = game_state::running;
}

void Game::quit() {
	state = game_state::quitting;
}

void Game::switchToScene(scene_num num) {


	switch (num) {
	case scene_num::mainmenu:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new MainMenu();
			scene->load();
		});
		break;
	case scene_num::level:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Level();
			scene->load();
		});
		break;
	case scene_num::stats:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Stats();
			scene->load();
		});
		break;
	case scene_num::options:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Options();
			scene->load();
		});
		break;
	case scene_num::credits:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Credits();
			scene->load();
		});
		break;
	
	}
		
}

void Game::addScript(function<void()> func) {
	scripts.push_back(func);
}

void Game::mainloop() { while (state != game_state::quitting) {
	time.update();
	exeScripts();
	input();
	if (state != game_state::paused)
		update();
	render();
	time.delay();
}}

void Game::exeScripts()
{
	size_t len = scripts.size();

	for (size_t i = 0; i < len; ++i)
		scripts[i]();

	scripts.clear();
}


void Game::input() {
	
	keyboard.resetOnceMasks();
	mouse.reset();


	SDL_Event ev;
	while (SDL_PollEvent(&ev)) { switch (ev.type) {

	case SDL_QUIT:         state = game_state::quitting;  break;
	case SDL_WINDOWEVENT:  
		switch (ev.window.event) 
		{
		case SDL_WINDOWEVENT_RESIZED: window.updateAll(); break;
		case SDL_WINDOWEVENT_MOVED:   window.updateAll(); break;
		}
		break;
	case SDL_KEYDOWN:      keyboard.processKeyDownEvent(ev.key);  break;
	case SDL_KEYUP:        keyboard.processKeyUpEvent(ev.key);    break;

	case SDL_MOUSEMOTION:      mouse.processMouseMoveEvent(ev.motion);        break;
	case SDL_MOUSEBUTTONDOWN:  mouse.processMouseButtonDownEvent(ev.button);  break;
	case SDL_MOUSEBUTTONUP:    mouse.processMouseButtonUpEvent(ev.button);    break;
	case SDL_MOUSEWHEEL:       mouse.processMouseWheelEvent(ev.wheel);        break;
	}}
	

	// GLOBAL
	if (keyboard.isKeyDownOnce(Key::KP_1))
		window.setFullscreen(Fullscreen::normal);
	if (keyboard.isKeyDownOnce(Key::KP_2))
		window.setFullscreen(Fullscreen::fake);
	if (keyboard.isKeyDownOnce(Key::KP_0))
		window.setFullscreen(Fullscreen::off);
	if (keyboard.isKeyDownOnce(Key::KP_3))
		window.setFullscreen(Fullscreen::window);



	scene->input();

}


void Game::update() {
	scene->update();
}

void Game::render() {

	SDL_SetRenderTarget(game.renderer, nullptr);
	renderer.setColor(color::black);
	SDL_RenderClear(renderer);

	scene->render(window.getTransform());

	SDL_RenderPresent(renderer);
}




