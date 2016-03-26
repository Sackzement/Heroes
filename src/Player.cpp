#include "Player.h"
#include "game.h"


void Player::update()  {
	if (game.keyboard.isKeyDown(SDL_SCANCODE_W) || game.keyboard.isKeyDown(SDL_SCANCODE_UP))
		pos.y -= game.time.getDelta() * speed;
	if (game.keyboard.isKeyDown(SDL_SCANCODE_A) || game.keyboard.isKeyDown(SDL_SCANCODE_LEFT))
		pos.x -= game.time.getDelta() * speed;
	if (game.keyboard.isKeyDown(SDL_SCANCODE_S) || game.keyboard.isKeyDown(SDL_SCANCODE_DOWN))
		pos.y += game.time.getDelta() * speed;
	if (game.keyboard.isKeyDown(SDL_SCANCODE_D) || game.keyboard.isKeyDown(SDL_SCANCODE_RIGHT))
		pos.x += game.time.getDelta() * speed;
}

void Player::render(Transform offset) const
{
	offset << *this;
	game.renderer.setColor(color::black);
	Rect::renderStatic(offset);
	renderChildren(offset);
}
