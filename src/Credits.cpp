#include "Credits.h"

#include "Game.h"
#include "Line.h"
#include "Rect.h"
#include "Color.h"



void Credits::input() {
	
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);
	if (game.mouse.isButtonDownOnce(SDL_BUTTON_RIGHT))
		game.switchToScene(scene_num::mainmenu);
}

void Credits::render(Transform offset) const
{
	offset << *this;

	renderBG(color::sky_brown, offset);


	// render grid
	game.renderer.setColor(color::white);
	for (double i = -8.; i <= 8.; ++i) { // vertical lines
		Transform off = offset;

		off << Transform(i, -4.5, 0.,
							0., 9.,
							0.);
		Line::renderStatic(off);
	}
	for (double i = -4.; i <= 4.; ++i) { // horizontal lines
		Transform off = offset;
		off << Transform(-8., i, 0.,
							16., 0.,
			0.);
		Line::renderStatic(off);
	}

	SDL_Color old_color = game.renderer.getColor();

	
	Transform off = offset; // draw Y line
	off << Transform(0.,-4.5, 0.,
						0., 9. , 
						0.);
	game.renderer.setColor(color::green);
	Line::renderStatic(off);

	off = offset; // draw X line
	off << Transform(-8., 0., 0.,
						16., 0., 
						0.);
	game.renderer.setColor(color::red);
	Line::renderStatic(off);


	game.renderer.setColor(old_color);

	renderChildren(offset);
}
