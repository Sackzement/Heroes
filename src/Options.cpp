#include "Options.h"
#include "Game.h"
#include "MainMenu.h"

Options::Options()
{
	btn_back.setFunction([]() {game.switchToScene(scene_num::mainmenu);});
	addObject(&btn_back);
}
