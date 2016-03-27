#include "Stats.h"
#include "Color.h"

#include "Game.h"
#include "Rect.h"



Stats::Stats() {

}

void Stats::input() {

	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);
	if (game.mouse.isButtonDownOnce(SDL_BUTTON_RIGHT))
		game.switchToScene(scene_num::mainmenu);
}

void Stats::render(Transform offset) const
{

	offset << *this;

	renderBG(color::sky_blue, offset);

	renderChildren(offset);
	
	Transform cube;
	cube.pos.set(-8.,0.,0.);
	for (int i = 0; i < 10; ++i) {
		Transform off = offset;
		off << cube;
		SDL_SetRenderDrawColor(game.renderer, 0x44, 0x44, 0x44, 0x00);
		Rect::renderStatic(off);
		cube.pos.x += 2.;
	}

	cube = Transform();
	cube.pos.set(-9., 1., 0.);
	for (int i = 0; i < 10; ++i) {
		Transform off = offset;
		off << cube;
		SDL_SetRenderDrawColor(game.renderer, 0x44, 0x44, 0x44, 0x00);
		Rect::renderStatic(off);
		cube.pos.x += 2.;
	}
}
