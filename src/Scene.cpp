#include "Scene.h"
#include "game.h"
#include "Rect.h"






double Scene::scale = 120.;


Scene::Scene() {
	pos.x = game.w / 2.;
	pos.y = game.h / 2.;
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

	Transform offset = *this;
	offset.pos  *= getScale();
	offset.size *= getScale();


	Transform bg_trans = offset;
	bg_trans.size.w *= game.w;
	bg_trans.size.h *= game.h;
	SDL_SetRenderDrawColor(game.renderer, 0x77, 0x77, 0x77, 0x77);
	Rect::renderStatic(bg_trans);

	renderChildren(offset);
}


void Scene::renderBG(SDL_Color col) const {

	Transform offset = *this;

	offset.pos *= getScale();
	offset.size *= getScale();
	offset.size.w *= game.w;
	offset.size.h *= game.h;
	game.renderer.setColor(col);
	Rect::renderStatic(offset);

}