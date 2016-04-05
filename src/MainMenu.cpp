#include "MainMenu.h"
#include "game.h"
#include "Options.h"
#include "Color.h"
#include "Rect.h"



const double btn_height = 1.;
const double half_btn_height = btn_height * .5;
const int num_btns = 6;



MainMenu::MainMenu() : selection(1) {

	title.text = "SUPER CRATE BOX";

	startgame.text = "START GAME";
	stats.text = "STATS";
	options.text = "OPTIONS";
	credits.text = "CREDITS";
	leveleditor.text = "LEVEL EDITOR";
	quit.text = "QUIT";

	title    .set(0. , -3.5 + (0.*btn_height), 0.,14., btn_height, 0.);
	startgame.set(0. , -3.5 + (2.*btn_height), 0.,10., btn_height, 0.);
	stats    .set(0. , -3.5 + (3.*btn_height), 0., 8., btn_height, 0.);
	options  .set(0. , -3.5 + (4.*btn_height), 0., 9., btn_height, 0.);
	credits  .set(0. , -3.5 + (5.*btn_height), 0., 9., btn_height, 0.);
  leveleditor.set(0. , -3.5 + (6.*btn_height), 0.,11., btn_height, 0.);
	quit     .set(0. , -3.5 + (7.*btn_height), 0., 8., btn_height, 0.);

	addLoad(&title);
	addLoad(&startgame);
	addLoad(&stats);
	addLoad(&options);
	addLoad(&credits);
	addLoad(&leveleditor);
	addLoad(&quit);

	addRender(&title);
	addRender(&startgame);
	addRender(&stats);
	addRender(&options);
	addRender(&credits);
	addRender(&leveleditor);
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

	const double first_btn_top = startgame.pos.y - half_btn_height;
	const double first_btn_bot = startgame.pos.y + half_btn_height;
	const double last_btn_bot = quit.pos.y + half_btn_height;


	if (game.mouse.moved())
	{
		// mouse to scene
		Transform offset = *this;

		Transform mouse_trans = game.mouse.pos().to_Transform();
		mouse_trans.pos /= game.window.getScale();
		mouse_trans.pos.x -= game.w * .5;
		mouse_trans.pos.y -= game.h * .5;

		offset << mouse_trans;
		offset << mouse_trans;
		// ------------- mouse to scene   end
		Position mouse_pos_scene = offset.pos;


		if (mouse_pos_scene.y >= first_btn_top  &&  mouse_pos_scene.y <= last_btn_bot)
		{
			for (int i = 0; i < num_btns; ++i)

				if (mouse_pos_scene.y <= first_btn_bot + (double(i) * btn_height)) {
					selection = i + 1;
					break;
				}

		}
		else
			selection = 0;
	}



	if (game.mouse.isButtonDownOnce(SDL_BUTTON_LEFT)) {

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
				game.switchToScene(scene_num::leveleditor);
				break;
			case 6:
				game.quit();
				break;
			default:
				selection = 1;
				break;
			}
	}

	if (game.mouse.isButtonDownOnce(SDL_BUTTON_RIGHT))
		game.quit();
	if (game.keyboard.isKeyDownOnce(Key::Q))
		game.quit();


	if (game.keyboard.isKeyDownOnce(Key::SPACE))
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
			game.switchToScene(scene_num::leveleditor);
			break;
		case 6:
			game.quit();
			break;
		default:
			selection = 1;
			break;
		}

	if (game.keyboard.isKeyDownOnce(Key::DOWN)) {
		if (selection >= 6)
			selection = 1;
		else
			++selection;
	}

	if (game.keyboard.isKeyDownOnce(Key::UP)) {
		
		if (selection <= 1)
			selection = 6;
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
	bg_trans.scale.x *= game.w;
	bg_trans.scale.y *= game.h;
	game.renderer.setColor(color::sky_brown);
	Rect::renderStatic(bg_trans);


	// render selection
	if (selection >= 1 && selection <= 6) {

		Transform off_sele = offset;
		Transform sele;
		sele.pos.y = (startgame.pos.y - btn_height) + (btn_height * (double)selection);
		sele.scale.x = 16.;
		sele.scale.y = btn_height;
		off_sele << sele;



		game.renderer.setColor(color::selection_dark);
		Rect::renderStatic(off_sele);
		//renderRect(offset.pos.x, offset.pos.y, offset.size.w, offset.size.h, color::selection_dark);
	}



	// render text
	renderChildren(offset);

	// test
	SDL_Color old_col = game.renderer.getColor(); game.renderer.setColor(color::black);
	Transform oo = offset, tt;
	tt.pos.set(-7, -3.5);
	tt.render(oo);
	game.renderer.setColor(old_col);
}
