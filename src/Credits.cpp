#include "Credits.h"

#include "Game.h"
#include "Line.h"
#include "Rect.h"
#include "Color.h"



void Credits::input() {
	
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);
}

void Credits::render() const
{
	renderBG(color::sky_brown);


	// render grid
	game.renderer.setColor(color::white);
	for (double i = -8.; i <= 8.; ++i) { // vertical lines
		Transform offset = *this;
		offset.pos *= getScale();
		offset.size *= getScale();

		offset << Transform(i, -4.5, 0.,
							0., 9.,
							0.);
		Line::renderStatic(offset);
	}
	for (double i = -4.; i <= 4.; ++i) { // horizontal lines
		Transform offset = *this;
		offset.pos *= getScale();
		offset.size *= getScale();
		offset << Transform(-8., i, 0.,
							16., 0.,
			0.);
		Line::renderStatic(offset);
	}

	SDL_Color old_color = game.renderer.getColor();
	Transform offset;

	offset = *this; // draw Y line
	offset.pos  *= getScale();
	offset.size *= getScale();
	offset << Transform(0.,-4.5, 0., 
						0., 9. , 
						0.);
	game.renderer.setColor(color::green);
	Line::renderStatic(offset);

	offset = *this; // draw X line
	offset.pos  *= getScale();
	offset.size *= getScale();
	offset << Transform(-8., 0., 0., 
						16., 0., 
						0.);
	game.renderer.setColor(color::red);
	Line::renderStatic(offset);


	game.renderer.setColor(old_color);
	offset = *this; 
	offset.pos *= getScale();
	offset.size *= getScale();
	renderChildren(offset);
}
