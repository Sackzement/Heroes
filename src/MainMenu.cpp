#include "MainMenu.h"
#include "game.h"
#include "Options.h"

MainMenu::MainMenu() {
	addObject(&player);

	btn_start.pos = { 0.2,1 };
	btn_options.pos = { 2,5 };
	btn_quit.pos = { 2,8 };

	Texture btn_tex = Texture(780, 66);
	btn_start.setTextures(btn_tex, btn_tex, btn_tex);
	btn_options.setTextures(btn_tex, btn_tex, btn_tex);
	btn_quit.setTextures(btn_tex, btn_tex, btn_tex);

	addObject(&btn_start);
	addObject(&btn_options);
	addObject(&btn_quit);

	btn_start.setFunction([]() {game.switchToScene(scene_num::level); });
	btn_options.setFunction([]() {game.switchToScene(scene_num::options); });
	btn_quit.setFunction([]() { game.quit(); } );
}

// LOAD ==================
bool MainMenu::load() {
	if (!loadChildren()) return false;


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


	return true;
}

void MainMenu::input()
{
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.quit();
	inputChildren();
}

