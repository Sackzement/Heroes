#include "Options.h"
#include "Game.h"
#include "MainMenu.h"

Options::Options()
{
	btn_back.setFunction([]() {game.switchToScene(scene_num::mainmenu);});
	addObject(&btn_back);
}


void Options::input() {

	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);

	if (game.mouse.isButtonDownOnce(SDL_BUTTON_RIGHT))
		game.switchToScene(scene_num::mainmenu);

	inputChildren();
}