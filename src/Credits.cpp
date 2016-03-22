#include "Credits.h"

#include "Game.h"
#include "Line.h"
#include "Rect.h"



void Credits::input() {
	
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);
}

void Credits::render() const
{
	// render bg
	Transform scene_trans = *this;
	scene_trans.size.w *= game.w;
	scene_trans.size.h *= game.h;
	SDL_SetRenderDrawColor(game.renderer, 0x22, 0x22, 0x00, 0x00);
	Rect::renderStatic(scene_trans);


	// render grid
	SDL_SetRenderDrawColor(game.renderer,255,255,255,0);
	for (double i = -8.; i <= 8.; ++i) { // vertical lines
		Transform offset = *this;
		offset << Transform(i, 0., 0., 0., 9., 90.);
		Line::renderStatic(offset);
	}
	for (double i = -4.; i <= 4.; ++i) { // horizontal lines
		Transform offset = *this;
		offset << Transform(0., i, 0., 16., 0., 0.);
		Line::renderStatic(offset);
	}

	SDL_Color old_color = game.renderer.getColor();
	Transform offset;

	offset = *this; // draw Y line
	offset << Transform(0., 0., 0., 0., 9., 90.);
	SDL_SetRenderDrawColor(game.renderer, 0, 255, 0, 0);
	Line::renderStatic(offset);

	offset = *this; // draw X line
	offset << Transform(0., 0., 0., 0., 16., 0.);
	SDL_SetRenderDrawColor(game.renderer, 255, 0, 0, 0);
	Line::renderStatic(offset);

	game.renderer.setColor(old_color);

	renderChildren(*this);
}
