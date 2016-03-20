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
		pos.x = (game.window.w - (scale*game.w) ) / 2.;
		pos.y = 0.;
		size.w = scale;
		size.h = scale;
	}
	else {
		double scale = scaleW;
		pos.x = 0.;
		pos.y = (game.window.h - (scale*game.h) ) / 2;
		size.w = scale;
		size.h = scale;
	}

}

double Scene::pixelToUnits(double pix)
{
	return pix / size.w;
}
  



void Scene::render() const {
	
	SDL_Rect rect = { (int)pos.x,(int)pos.y,int(size.w*game.w),int(size.h*game.h) };
	SDL_SetRenderDrawColor(game.renderer, 0xb4, 0xd4, 0xee, 0x0);
	SDL_RenderFillRect(game.renderer, &rect);

	renderChildren(*this);
}