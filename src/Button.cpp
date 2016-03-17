#include "Button.h"
#include "game.h"

Button::Button()
	: m_state(bt_state::normal)
{}
void Button::setTextures(Texture normal, Texture highlighted, Texture pressed)
{
	m_textureNormal = normal;
	m_textureHighlighted = highlighted;
	m_texturePressed = pressed;
}
void Button::highlight() {
	m_state = bt_state::highlighted;
}
void Button::unhighlight() {
	m_state = bt_state::normal;
}
void Button::press()
{
	m_state = bt_state::pressed;
}
void Button::render(Transform offset) const {

	Texture toDraw;

	switch (m_state)
	{
	case bt_state::normal:
		toDraw = m_textureNormal;
		break;
	case bt_state::highlighted:
		toDraw = m_textureHighlighted;
		break;
	case bt_state::pressed:
		toDraw = m_texturePressed;
		break;
	}

	offset << *this;

	SDL_Rect dst = offset.toRect();

	SDL_RenderCopyEx(game.renderer, toDraw, nullptr, &dst, rot, nullptr, SDL_FLIP_NONE);
}
