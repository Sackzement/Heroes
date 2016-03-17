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

	SDL_RenderDrawPoint(game.renderer, (int)offset.pos.x, (int)offset.pos.y);

	SDL_Rect rect = offset.toRect();
	SDL_RenderDrawRect(game.renderer, &rect);

	renderChildren(offset);
}



void Object::addChild(Object * ch) {

}
void Object::addChild(Load   * lo) {

}
void Object::addChild(Input  * in) {

}
void Object::addChild(Update * up) {

}
void Object::addChild(Render * re) {

}

void Object::addLoad(Load   * lo) {

}
void Object::addInput(Input  * in) {

}
void Object::addUpdate(Update * up) {

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