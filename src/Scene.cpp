#include "Scene.h"
#include "game.h"








Scene::Scene() {
	rescale();
}

bool Scene::load() {
	rescale();
	return loadChildren();
}


void Scene::rescale() {
	double scaleW = double(game.window.w) / game.w;
	double scaleH = double(game.window.h) / game.h;

	if (scaleH < scaleW) {
		double scale = scaleH;
		//pos.x = (game.window.w - (scale*game.w) ) / 2.;
		//pos.y = 0.;
		size.w = scale;
		size.h = scale;
	}
	else {
		double scale = scaleW;
		//pos.x = 0.;
		//pos.y = (game.window.h - (scale*game.h) ) / 2;
		size.w = scale;
		size.h = scale;
	}

}

double Scene::pixelToUnits(double pix)
{
	return pix / size.w;
}
  
Position Scene::pixelToPos(Position2i pos)
{
	Position ret;
	ret.x = double(pos.x) - ((double)game.window.w / 2.);
	ret.y = double(pos.y) - ((double)game.window.h / 2.);
	ret.x /= size.w;
	ret.y /= size.h;

	return ret;
}


void Scene::render() const {
	
	SDL_Rect rect = {	(int)pos.x + (game.window.w / 2),
						(int)pos.y + (game.window.h / 2),
						int(size.w*game.w),
						int(size.h*game.h) };
	rect.x -= rect.w / 2;
	rect.y -= rect.h / 2;


	SDL_SetRenderDrawColor(game.renderer,0x77,0x77,0x77,0x77);
	SDL_RenderFillRect(game.renderer, &rect);

	renderChildren(*this);
}