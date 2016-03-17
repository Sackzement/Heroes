#include "Game.h"
#include "Libs.h"
#include "MainMenu.h"
//#include "HardwareInfo.h"

#include "Scene.h"




Game game;









void Game::start() {
	Libs::init();
	window.create();
	renderer.create();
	time.resetDelay();

	scene = new MainMenu();

	mainloop();

	renderer.destroy();
	window.destroy();
	Libs::quit();
}

void Game::mainloop() { while (!quit) {
	time.update();
	input();
	update();
	render();
	time.delay();
}}


void Game::input() {
	
	keyboard.resetOnceMasks();

	SDL_Event ev;
	
	while (SDL_PollEvent(&ev)) { switch (ev.type) {

	case SDL_QUIT:     quit = true;                           break;
	case SDL_KEYDOWN:  keyboard.processKeyDownEvent(ev.key);  break;  // update keyboard
	case SDL_KEYUP:    keyboard.processKeyUpEvent(ev.key);    break;  // update keyboard }

	}}
	
	scene->input();

}


void Game::update() {
	scene->update();
}

void Game::render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	scene->render();

	SDL_RenderPresent(renderer);
}




