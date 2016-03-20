#pragma once
#include "Object.h"
#include "Texture.h"
#include <functional>
using std::function;


class Button : virtual public Object {

protected:
	enum class bt_state {
		normal,
		highlighted,
		pressed,
	};

public:
	bt_state state;
	std::function<void()> pressfunction;
	

	Texture  textureNormal;
	Texture  textureHighlighted;
	Texture  texturePressed;


	     Button();
		 virtual ~Button() {}
	void setTextures(Texture normal, Texture highlighted, Texture pressed);
	void setFunction(function<void()> func);
	void setState(bt_state st);
	void highlight();
	void unhighlight();
	void press();

	void input() override;
	void render(Transform offset) const override;
};


