#include "Game.h"
#include "Libs.h"
#include "MainMenu.h"
#include "Options.h"
#include "Level.h"
//#include "HardwareInfo.h"

#include "Scene.h"




Game game;







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
	window.create();
	renderer.create();

	scene = new MainMenu();
	scene->rescale();
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
	mouse.resetOnceMasks();
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) { switch (ev.type) {
	case SDL_QUIT:         state = game_state::quitting;  break;
	case SDL_WINDOWEVENT:  if (ev.window.event == SDL_WINDOWEVENT_RESIZED) { 
		window.pullSize();
		scene->rescale(); 
	}  break;
	case SDL_KEYDOWN:      keyboard.processKeyDownEvent(ev.key);  break;
	case SDL_KEYUP:        keyboard.processKeyUpEvent(ev.key);    break;
	case SDL_MOUSEMOTION:      mouse.processMouseMoveEvent(ev.motion);        break;
	case SDL_MOUSEBUTTONDOWN:  mouse.processMouseButtonDownEvent(ev.button);  break;
	case SDL_MOUSEBUTTONUP:    mouse.processMouseButtonUpEvent(ev.button);    break;
	}}
	
	scene->input();

}


void Game::update() {
	scene->update();
}

void Game::render() {

	SDL_SetRenderTarget(game.renderer, nullptr);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	scene->render();

	SDL_RenderPresent(renderer);
}




