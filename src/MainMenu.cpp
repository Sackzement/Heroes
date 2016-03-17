#include "MainMenu.h"
#include "Button.h"
#include "Player.h"
#include "game.h"

MainMenu::MainMenu() {

}

// LOAD ==================
bool MainMenu::load() 
{
	loadButtons();

	Player* player = new Player();
	addInput(player);
	addUpdate(player);
	addRender(player);

	loadChildren();
	return true;
}





bool MainMenu::loadButtons() {
	int btn_w = 1920 / 6;
	int btn_h = btn_w / 3;

	SDL_Texture* texs[3];

	for (int i = 0; i<3; ++i)
		texs[i] = SDL_CreateTexture(game.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, btn_w, btn_h);

	for (int i = 0; i < 3; ++i) {
		SDL_SetRenderTarget(game.renderer, texs[i]);
		SDL_SetRenderDrawColor(game.renderer, 255 - (i * 50), 0, 0, 0);
		SDL_RenderClear(game.renderer);
	}


	Button * Button_Start = new Button();//, Button_Settings, Button_Quit;

	Button_Start->pos.x = 4;
	Button_Start->pos.y = 3;
	Button_Start->size.w = 2;
	Button_Start->size.h = 2. / 3.;

	Texture texx[3];
	for (int i = 0; i < 3; ++i)
		texx[i].texture = texs[i];

	Button_Start->setTextures(texx[0], texx[1], texx[2]);

	addRender(Button_Start);

	return true;
}