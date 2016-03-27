#include "Scene.h"
#include "game.h"
#include "Rect.h"

#include <SDL/SDL_assert.h>







bool Scene::load() {
	return loadChildren();
}



double Scene::pixelToUnits(double pix)
{
	return pix;// / scale;
}
  
Position Scene::pixelToPos(Position2i pos)
{
	Position ret;
	ret.x = double(pos.x) - ((double)game.window.w / 2.);
	ret.y = double(pos.y) - ((double)game.window.h / 2.);
	//ret.x /= scale;
	//ret.y /= scale;
	SDL_assert(false); // replace / delete ?

	return ret;
}


void Scene::render(Transform offset) const {

	offset << *this;


	Transform bg_trans = offset;
	bg_trans.size.w *= game.w;
	bg_trans.size.h *= game.h;
	SDL_SetRenderDrawColor(game.renderer, 0x77, 0x77, 0x77, 0x77);
	Rect::renderStatic(bg_trans);

	renderChildren(offset);
}


void Scene::renderBG(SDL_Color col, Transform offset) const {

	offset.size.w *= game.w;
	offset.size.h *= game.h;

	game.renderer.setColor(col);
	Rect::renderStatic(offset);

}