#include "Stats.h"
#include "Color.h"

#include "Game.h"
#include "Rect.h"



Stats::Stats() {

}

void Stats::input() {

	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);
}

void Stats::render() const
{
	renderBG(color::sky_blue);

	Transform offset = *this;
	offset.pos *= getScale();
	offset.size *= getScale();

	renderChildren(offset);
	
	Transform cube;
	cube.pos.set(-8.,0.,0.);
	for (int i = 0; i < 10; ++i) {
		Transform offset = *this;
		offset << cube;
		offset.pos *= getScale();
		offset.size *= getScale();
		SDL_SetRenderDrawColor(game.renderer, 0x44, 0x44, 0x44, 0x00);
		Rect::renderStatic(offset);
		cube.pos.x += 2.;
	}

	cube = Transform();
	cube.pos.set(-9., 1., 0.);
	for (int i = 0; i < 10; ++i) {
		Transform offset = *this;
		offset << cube;
		offset.pos *= getScale();
		offset.size *= getScale();
		SDL_SetRenderDrawColor(game.renderer, 0x44, 0x44, 0x44, 0x00);
		Rect::renderStatic(offset);
		cube.pos.x += 2.;
	}
}
