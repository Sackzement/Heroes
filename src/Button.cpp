#include "Button.h"
#include "game.h"

Button::Button()
	: state(bt_state::normal)
{
	addLoad(&textureNormal);
	addLoad(&textureHighlighted);
	addLoad(&texturePressed);

	setFunction([]() {});
}
void Button::setTextures(Texture normal, Texture highlighted, Texture pressed)
{
	textureNormal = normal;
	textureHighlighted = highlighted;
	texturePressed = pressed;
}
void Button::setFunction(function<void()> func) {
	pressfunction = func;
}
void Button::setState(bt_state st) {
	state = st;
}
bool Button::isHighlighted()
{
	if (state == bt_state::highlighted)
		return true;
	else
		return false;
}
void Button::highlight() {
	state = bt_state::highlighted;
}
void Button::unhighlight() {
	state = bt_state::normal;
}
void Button::press()
{
	state = bt_state::pressed;
}


void Button::input() {

	Transform offset = *(game.scene);
	offset << *this;
	SDL_Rect rect = offset.toRect();

	rect.x += (game.window.w / 2) - (rect.w / 2);
	rect.y += (game.window.h / 2) - (rect.h / 2);

	SDL_Point point = { game.mouse.x(), game.mouse.y() };

	SDL_bool res = SDL_PointInRect(&point, &rect);
	if (res) {
		if (game.mouse.isButtonUp(SDL_BUTTON_LEFT))
		state = bt_state::highlighted;
		else {
			state = bt_state::pressed;
			pressfunction();
		}

	}
}


void Button::render(Transform offset) const {

	Texture toDraw;

	switch (state)
	{
	case bt_state::normal:
		toDraw = textureNormal;
		break;
	case bt_state::highlighted:
		toDraw = textureHighlighted;
		break;
	case bt_state::pressed:
		toDraw = texturePressed;
		break;
	}

	offset << *this;

	SDL_Rect dst = offset.toRect();

	toDraw.render(offset);
	//SDL_RenderCopyEx(game.renderer, toDraw, nullptr, &dst, rot, nullptr, SDL_FLIP_NONE);
}
