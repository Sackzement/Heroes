#include "MainMenu.h"
#include "game.h"
#include "Options.h"

MainMenu::MainMenu() : selection(0) {

	title.text = "SUPER CRATE BOX";

	startgame.text = "START GAME";
	stats.text = "STATS";
	options.text = "OPTIONS";
	credits.text = "CREDITS";
	quit.text = "QUIT";

	title    .set(0. , -4.5 + 1.  , 0.,14., 1.5, 0.);
	startgame.set(0. , -4.5 + 3.5 , 0.,10., 1.5, 0.);
	stats    .set(0. , -4.5 + 4.5 , 0., 8., 1.5, 0.);
	options  .set(0. , -4.5 + 5.5 , 0., 9., 1.5, 0.);
	credits  .set(0. , -4.5 + 6.5 , 0., 9., 1.5, 0.);
	quit     .set(0. , -4.5 + 7.5 , 0., 8., 1.5, 0.);

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
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.quit();


	else if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_SPACE))
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

	else if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_DOWN)) {
		if (selection >= 5)
			selection = 1;
		else
			++selection;
	}

	else if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_UP)) {
		
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



void renderRect(double xx, double yy, double ww, double hh, Uint8 r, Uint8 g, Uint8 b, Uint8 a ) {

	SDL_Rect rect = {	(int)xx + (game.window.w/2),
						(int)yy + (game.window.h/2),
						(int)ww,
						(int)hh  };
	rect.x -= rect.w / 2;
	rect.y -= rect.h / 2;

	Uint8	old_r,
			old_g,
			old_b,
			old_a;
	SDL_GetRenderDrawColor(game.renderer, &old_r, &old_g, &old_b, &old_a);

	SDL_SetRenderDrawColor(game.renderer, r, g, b, a);
	SDL_RenderFillRect(game.renderer, &rect);
	SDL_SetRenderDrawColor(game.renderer, old_r, old_g, old_b, old_a);
}

void MainMenu::render() const
{
	// render BG color
	SDL_Rect rect = {	(int)pos.x + (game.window.w/2) ,
						(int)pos.y + (game.window.h/2) ,
						int(size.w*game.w),
						int(size.h*game.h)  };
	rect.x -= rect.w / 2;
	rect.y -= rect.h / 2;

	SDL_SetRenderDrawColor(game.renderer,0x3b,0x32, 0x24,0x0);
	SDL_RenderFillRect(game.renderer, &rect);


	// render selection
	if (selection >= 1 && selection <= 5) {

		Transform offset = *this;
		Transform sele;
		sele.pos.y = -1. + double(selection - 1);
		sele.size.w = 16.;
		sele.size.h = 1.2;
		offset << sele;

		renderRect(offset.pos.x, offset.pos.y, offset.size.w, offset.size.h, 255, 0, 0, 0);
	}



	// render text
	renderChildren(*this);
}
