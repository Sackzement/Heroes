#pragma once
#include "Object.h"
#include "Texture.h"


class Button : virtual public Object {

	enum class bt_state {
		normal,
		highlighted,
		pressed,
	};

protected:
	bt_state m_state;
	Texture  m_textureNormal;
	Texture  m_textureHighlighted;
	Texture  m_texturePressed;

public:
	     Button();
	void setTextures(Texture normal, Texture highlighted, Texture pressed);
	void highlight();
	void unhighlight();
	void press();

	void render(Transform offset) const override;
};