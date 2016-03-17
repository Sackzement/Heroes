#include "Scene.h"
#include "game.h"



void Scene::rescale() {
	double scaleW = double(game.window.w) / game.w;
	double scaleH = double(game.window.h) / game.h;

	if (scaleH < scaleW)
		size = scaleH;
	else
		size = scaleW;

}
  



void Scene::render() const {

	SDL_RenderDrawPoint(game.renderer, (int)pos.x, (int)pos.y);

	SDL_Rect rect = this->toRect();
	SDL_RenderDrawRect(game.renderer, &rect);

	renderChildren(*this);
}