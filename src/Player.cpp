#include "Player.h"
#include "game.h"


void Player::update()  {
	if (game.keyboard.isKeyDown(SDL_SCANCODE_W))
		pos.y -= game.time.getDelta() * speed;
	if (game.keyboard.isKeyDown(SDL_SCANCODE_A))
		pos.x -= game.time.getDelta() * speed;
	if (game.keyboard.isKeyDown(SDL_SCANCODE_S))
		pos.y += game.time.getDelta() * speed;
	if (game.keyboard.isKeyDown(SDL_SCANCODE_D))
		pos.x += game.time.getDelta() * speed;
}