#include "LevelEditor.h"
#include "Game.h"
#include "Text.h"

#include <iostream>
using std::cout;
using std::endl;






LevelEditor::LevelEditor() 
{
}






void LevelEditor::input()
{
	// return to main menu
	if (game.keyboard.isKeyDownOnce(Key::Q))
		game.switchToScene(scene_num::mainmenu);
	if (game.mouse.isButtonDownOnce(SDL_BUTTON_RIGHT))
		game.switchToScene(scene_num::mainmenu);

	// mouse move funcs
	if ( game.mouse.did_move() )
	{
		// + MMB down -> move scene
		if (game.mouse.isButtonDown(SDL_BUTTON_MIDDLE))
			this->pos += pixelDistToSceneDist(game.mouse.dist_moved());


		// + LMB down -> move selected
		if (game.mouse.isButtonDown(SDL_BUTTON_LEFT)) {

			const size_t len_selection = selection.size();
			if (len_selection > 0)
				for (size_t i = 0; i < len_selection; ++i)
					selection[i]->pos += pixelDistToSceneDist(game.mouse.dist_moved());
		}


	}
}





void LevelEditor::render(Transform offset) const
{
	offset << *this;

	renderBG(color::sky_brown, offset);


	// print mouse pos
	Position2i mouse_pos = game.mouse.getPos();
	cout << "\nMouse pixel pos:  " << mouse_pos.x << "  " << mouse_pos.y;
	Position mouse_pos_screen = pixelToScreenUnits(mouse_pos);
	cout << "\nMouse scene pos:  " << mouse_pos_screen.x << "  " << mouse_pos_screen.y;
	Position mouse_pos_scene = screenUnitsToScene(mouse_pos_screen);
	cout << "\nMouse scene pos:  " << mouse_pos_scene.x << "  " << mouse_pos_scene.y;

	SDL_assert("LevelEditor render" && 0); // replace / delete ?

	// render children
	renderChildren(offset);

	// render text mouse pos
	Text mouse_text;
	mouse_text.pos.set(-7., -3.5);
	mouse_text.scale.set(2., .5);
	mouse_text.color = color::red;
	mouse_text.text = string() + "Mouse pos:  " + to_string_prec(mouse_pos_scene.x) + "  " + to_string_prec(mouse_pos_scene.y);
	mouse_text.load();
	mouse_text.render(game.window.getTransform());
	mouse_text.unload();
}
