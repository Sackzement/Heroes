#include "Scene.h"
#include "game.h"
#include "Rect.h"

#include <SDL/SDL_assert.h>







bool Scene::load() {
	return loadChildren();
}



double Scene::pixelToUnits(double pix)
{
	SDL_assert("pixelToUnits" && 0); // replace / delete ?
	return pix;// / scale;
}
  
Position Scene::pixelToPos(Position2i pos)
{
	Position ret;
	ret.x = double(pos.x) - ((double)game.window.getSize().w / 2.);
	ret.y = double(pos.y) - ((double)game.window.getSize().h / 2.);
	//ret.x /= scale;
	//ret.y /= scale;
	SDL_assert("pixelToPos" && 0); // replace / delete ?

	return ret;
}


void Scene::render(Transform offset) const {

	offset << *this;


	Transform bg_trans = offset;
	bg_trans.scale.x *= game.w;
	bg_trans.scale.y *= game.h;
	SDL_SetRenderDrawColor(game.renderer, 0x77, 0x77, 0x77, 0x77);
	Rect::renderStatic(bg_trans);

	renderChildren(offset);
}

void Scene::setCamera(Transform camera_trans)
{
	pos   = camera_trans.pos * -1.;
	scale = camera_trans.scale;
	rot   = camera_trans.rot;
}


void Scene::renderBG(SDL_Color col, Transform offset) const {

	offset.scale.x *= game.w;
	offset.scale.y *= game.h;

	game.renderer.setColor(col);
	Rect::renderStatic(offset);

}