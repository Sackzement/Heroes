#include "MainMenu.h"
#include "game.h"
#include "Options.h"
#include "Color.h"
#include "Rect.h"

MainMenu::MainMenu() : selection(1) {

	title.text = "SUPER CRATE BOX";

	startgame.text = "START GAME";
	stats.text = "STATS";
	options.text = "OPTIONS";
	credits.text = "CREDITS";
	quit.text = "QUIT";

	title    .set(0. , -3.5 + (0.*1.2), 0.,14., 1.2, 0.);
	startgame.set(0. , -3.5 + (2.*1.2), 0.,10., 1.2, 0.);
	stats    .set(0. , -3.5 + (3.*1.2), 0., 8., 1.2, 0.);
	options  .set(0. , -3.5 + (4.*1.2), 0., 9., 1.2, 0.);
	credits  .set(0. , -3.5 + (5.*1.2), 0., 9., 1.2, 0.);
	quit     .set(0. , -3.5 + (6.*1.2), 0., 8., 1.2, 0.);

	addLoad(&title);
	addLoad(&startgame);
	addLoad(&stats);
	addLoad(&options);
	addLoad(&credits);
	addLoad(&quit);

	addRender(&title);
	addRender(&startgame);
	addRender(&stats);
	addRender(&options);
	addRender(&credits);
	addRender(&quit);


	/*
	Texture btn_tex = Texture(780, 66);
	btn_start.setTextures(btn_tex, btn_tex, btn_tex);
	btn_options.setTextures(btn_tex, btn_tex, btn_tex);
	btn_quit.setTextures(btn_tex, btn_tex, btn_tex);

	addObject(&btn_start);
	addObject(&btn_options);
	addObject(&btn_quit);

	btn_start.setFunction([]() {game.switchToScene(scene_num::level); });
	btn_options.setFunction([]() {game.switchToScene(scene_num::options); });
	btn_quit.setFunction([]() { game.quit(); } );*/
}

// LOAD ==================
bool MainMenu::load() {
	if (!loadChildren()) return false;


	/*
	//  COLORIZE BUTTON TEXTURES
	SDL_SetRenderTarget(game.renderer,btn_start.textureNormal);
	SDL_SetRenderDrawColor(game.renderer, 255, 0, 0, 0);
	SDL_RenderClear(game.renderer);
	SDL_SetRenderTarget(game.renderer, btn_start.textureHighlighted);
	SDL_SetRenderDrawColor(game.renderer, 166, 0, 0, 0);
	SDL_RenderClear(game.renderer);
	SDL_SetRenderTarget(game.renderer, btn_start.texturePressed);
	SDL_SetRenderDrawColor(game.renderer, 100, 0, 0, 0);
	SDL_RenderClear(game.renderer);


	SDL_SetRenderTarget(game.renderer, btn_options.textureNormal);
	SDL_SetRenderDrawColor(game.renderer, 0, 255, 0, 0);
	SDL_RenderClear(game.renderer);
	SDL_SetRenderTarget(game.renderer, btn_options.textureHighlighted);
	SDL_SetRenderDrawColor(game.renderer, 0, 166, 0, 0);
	SDL_RenderClear(game.renderer);
	SDL_SetRenderTarget(game.renderer, btn_options.texturePressed);
	SDL_SetRenderDrawColor(game.renderer, 0, 100, 0, 0);
	SDL_RenderClear(game.renderer);


	SDL_SetRenderTarget(game.renderer, btn_quit.textureNormal);
	SDL_SetRenderDrawColor(game.renderer, 0, 0, 100,0 );
	SDL_RenderClear(game.renderer);
	SDL_SetRenderTarget(game.renderer, btn_quit.textureHighlighted);
	SDL_SetRenderDrawColor(game.renderer, 0, 0, 166, 0);
	SDL_RenderClear(game.renderer);
	SDL_SetRenderTarget(game.renderer, btn_quit.texturePressed);
	SDL_SetRenderDrawColor(game.renderer, 0, 0, 255, 0);
	SDL_RenderClear(game.renderer);
	*/

	return true;
}

void MainMenu::input()
{
	if (game.mouse.moved())
	{
		// mouse to scene
		Transform offset = *this;

		Transform mouse_trans = game.mouse.pos();
		mouse_trans.pos /= game.getScale();
		mouse_trans.pos.x -= game.w * .5;
		mouse_trans.pos.y -= game.h * .5;

		offset << mouse_trans;
		offset << mouse_trans;
		// ------------- mouse to scene   end
		Position mouse_pos_scene = offset.pos;

		if (mouse_pos_scene.y >= startgame.pos.y - .6
			&& mouse_pos_scene.y <= startgame.pos.y + (4.*1.2) + .6)
		{
			if (mouse_pos_scene.y < -1. + .75)
				selection = 1;
			else if (mouse_pos_scene.y < -1. + .6 + (1 * 1.2))
				selection = 2;
			else if (mouse_pos_scene.y < -1. + .6 + (2 * 1.2))
				selection = 3;
			else if (mouse_pos_scene.y < -1. + .6 + (3 * 1.2))
				selection = 4;
			else if (mouse_pos_scene.y < -1. + .6 + (4 * 1.2))
				selection = 5;
		}
		else
			selection = 0;
	}
	if (game.mouse.isButtonDownOnce(SDL_BUTTON_LEFT)) {

		Transform offset = *this;

		Transform mouse_trans = game.mouse.pos();
		mouse_trans.pos /= game.getScale();
		mouse_trans.pos.x -= game.w * .5;
		mouse_trans.pos.y -= game.h * .5;

		offset << mouse_trans;
		offset << mouse_trans;

		Position mouse_pos_scene = offset.pos;

		if (mouse_pos_scene.y >= startgame.pos.y - .6
			&& mouse_pos_scene.y <= startgame.pos.y + (4.*1.2) + .6)
		{
			switch (selection)
			{
			case 1:
				game.switchToScene(scene_num::level);
				break;
			case 2:
				game.switchToScene(scene_num::stats);
				break;
			case 3:
				game.switchToScene(scene_num::options);
				break;
			case 4:
				game.switchToScene(scene_num::credits);
				break;
			case 5:
				game.quit();
				break;
			default:
				selection = 1;
				break;
			}
		}
		else
			selection = 0;
	}

	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.quit();


	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_SPACE))
		switch (selection)
		{
		case 1:
			game.switchToScene(scene_num::level);
			break;
		case 2:
			game.switchToScene(scene_num::stats);
			break;
		case 3:
			game.switchToScene(scene_num::options);
			break;
		case 4:
			game.switchToScene(scene_num::credits);
			break;
		case 5:
			game.quit();
			break;
		default:
			selection = 1;
			break;
		}

	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_DOWN)) {
		if (selection >= 5)
			selection = 1;
		else
			++selection;
	}

	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_UP)) {
		
		if (selection <= 1)
			selection = 5;
		else
			--selection;
	}


	inputChildren();

}


void MainMenu::update()
{
	//title.rot += 100. * game.time.getDelta();
}



/*void renderRect(double xx, double yy, double ww, double hh, SDL_Color color ) {

	SDL_Rect rect = {	(int)xx + (game.window.w/2),
						(int)yy + (game.window.h/2),
						(int)ww,
						(int)hh  };
	rect.x -= rect.w / 2;
	rect.y -= rect.h / 2;

	SDL_Color old_color = game.renderer.getColor();
	game.renderer.setColor(color);
	SDL_RenderFillRect(game.renderer, &rect);
	game.renderer.setColor(old_color);
}*/
void MainMenu::render(Transform offset) const
{
	offset << *this;


	// render BG color
	Transform bg_trans = offset;
	bg_trans.size.w *= game.w;
	bg_trans.size.h *= game.h;
	game.renderer.setColor(color::sky_brown);
	Rect::renderStatic(bg_trans);


	// render selection
	if (selection >= 1 && selection <= 5) {

		Transform off_sele = offset;
		Transform sele;
		sele.pos.y = (startgame.pos.y - 1.2) + (1.2 * (double)selection);
		sele.size.w = 16.;
		sele.size.h = 1.2;
		off_sele << sele;



		game.renderer.setColor(color::selection_dark);
		Rect::renderStatic(off_sele);
		//renderRect(offset.pos.x, offset.pos.y, offset.size.w, offset.size.h, color::selection_dark);
	}



	// render text
	renderChildren(offset);
}
