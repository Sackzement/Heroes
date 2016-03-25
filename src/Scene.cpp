#include "Scene.h"
#include "game.h"
#include "Rect.h"






double Scene::scale = 120.;


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

	if (scaleH < scaleW)
		double scale = scaleH;
	else
		double scale = scaleW;

}

double Scene::pixelToUnits(double pix)
{
	return pix / scale;
}
  
Position Scene::pixelToPos(Position2i pos)
{
	Position ret;
	ret.x = double(pos.x) - ((double)game.window.w / 2.);
	ret.y = double(pos.y) - ((double)game.window.h / 2.);
	ret.x /= scale;
	ret.y /= scale;

	return ret;
}


void Scene::render() const {

	Transform scene_trans = *this;
	scene_trans.size.w *= game.w;
	scene_trans.size.h *= game.h;
	SDL_SetRenderDrawColor(game.renderer, 0x77, 0x77, 0x77, 0x77);
	Rect::renderStatic(scene_trans);

	renderChildren(*this);
}