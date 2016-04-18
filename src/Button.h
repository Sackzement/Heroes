#pragma once
#include "Object.h"
#include "TextureDraw.h"
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
	

	TextureDraw  textureNormal;
	TextureDraw  textureHighlighted;
	TextureDraw  texturePressed;


	     Button();
		 virtual ~Button() {}
	void setTextures(TextureDraw normal, TextureDraw highlighted, TextureDraw pressed);
	void setFunction(function<void()> func);
	void setState(bt_state st);
	bool isHighlighted();
	void highlight();
	void unhighlight();
	void press();

	void input() override;
	void render(Transform offset) const override;
};


