#include "Object.h"
#include "game.h"
#include "Color.h"
#include "Point.h"
#include "Rect.h"



// CONSTRUCTOR
Object:: Object()  :

m_type(obj_type::transform),

loads(),
inputs(),
updates(),
renders()

{}






Uint8 Object::type() const
{
	return m_type;
}

void Object::addType(Uint8 new_type) {
	m_type |= new_type;
}

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

	//game.renderer.setColor(color::white);
	//Point::renderStatic(offset);
	//Rect::renderStatic(offset);

	renderChildren(offset);
}



bool Object::addObject(Object * obj) {

	if (obj == nullptr)
		return false;

	if (obj->type() | obj_type::load) {
		loads.push_back(obj);
		m_type |= obj_type::load;
	}
	if (obj->type() | obj_type::input) {
		inputs.push_back(obj);
		m_type |= obj_type::input;
	}
	if (obj->type() | obj_type::update)  {
		updates.push_back(obj);
		m_type |= obj_type::update;
	}
	if (obj->type() | obj_type::render)  {
		renders.push_back(obj);
		m_type |= obj_type::render;
	}

	return true;
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
void Object::addRender(Transform * re) {
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