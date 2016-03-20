#include "Object.h"
#include "game.h"





Object::Object() {}



bool Object::load() {
	return loadChildren();
}
void Object::unload() {
	unloadChildren();
}



void Object::input() {
	inputChildren();
}
void Object::update() {
	updateChildren();
}
void Object::render(Transform offset) const {

	offset << *this;

	SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 0);
	SDL_RenderDrawPoint(game.renderer, (int)offset.pos.x, (int)offset.pos.y);

	SDL_Rect rect = offset.toRect();
	SDL_RenderDrawRect(game.renderer, &rect);

	renderChildren(offset);
}



void Object::addObject(Object * obj) {

	loads.push_back(obj);
	inputs.push_back(obj);
	updates.push_back(obj);
	renders.push_back(obj);
}

void Object::addLoad(Load   * lo) {
	if (lo != nullptr)
		loads.push_back(lo);
}
void Object::addInput(Input  * in) {
	if (in != nullptr)
		inputs.push_back(in);
}
void Object::addUpdate(Update * up) {
	if (up != nullptr)
		updates.push_back(up);
}
void Object::addRender(Render * re) {
	if (re != nullptr)
		renders.push_back(re);
}



bool Object::loadChildren() {
	bool success = true;
	size_t len = loads.size();
	for (size_t i = 0; i < len; ++i)
		if (!loads[i]->load())
			success = false;
	return success;
}
void Object::unloadChildren() {
	size_t len = loads.size();
	for (size_t i = 0; i<len; ++i)
		loads[i]->unload();
}
void Object::inputChildren() {
	size_t len = inputs.size();
	for (size_t i = 0; i<len; ++i)
		inputs[i]->input();
}
void Object::updateChildren() {
	size_t len = updates.size();
	for (size_t i = 0; i<len; ++i)
		updates[i]->update();
}
void Object::renderChildren(Transform offset) const {
	size_t len = renders.size();
	for (size_t i = 0; i<len; ++i)
		renders[i]->render(offset);
}