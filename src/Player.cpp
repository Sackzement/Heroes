#include "Player.h"
#include "game.h"



Player::Player()
{
	trans_update.nullify();
}

void Player::input()
{
	if (game.keyboard.isKeyDownOnce(Key::W) || game.keyboard.isKeyDown(Key::UP))
		pos.y -= game.time.getDelta() * speed;
	if (game.keyboard.isKeyDownOnce(Key::A) || game.keyboard.isKeyDownOnce(Key::LEFT))
		move_dir = direction::left;
	if (game.keyboard.isKeyDownOnce(Key::S) || game.keyboard.isKeyDown(Key::DOWN))
		pos.y += game.time.getDelta() * speed;
	if (game.keyboard.isKeyDownOnce(Key::D) || game.keyboard.isKeyDownOnce(Key::RIGHT))
		move_dir = direction::right;
	// jump();

	if (game.keyboard.isKeyUpOnce(Key::A) || game.keyboard.isKeyUpOnce(Key::LEFT)) {

		if (game.keyboard.isKeyDown(Key::D) || game.keyboard.isKeyDown(Key::RIGHT))
			move_dir = direction::right;
		else
			move_dir = direction::none;
	}
	if (game.keyboard.isKeyUpOnce(Key::D) || game.keyboard.isKeyUpOnce(Key::RIGHT)) {

		if (game.keyboard.isKeyDown(Key::A) || game.keyboard.isKeyDown(Key::LEFT))
		move_dir = direction::left;
		else
			move_dir = direction::none;

	}
}

void Player::update()  {

	// gravity
	trans_update.pos.y += gravity * game.time.getDelta();

	// left / right movement
	switch (move_dir) {

	case direction::left:
		trans_update.pos.x = -speed;
		break;
	case direction::right:
		trans_update.pos.x = +speed;
		break;
	default:
		trans_update.pos.x = 0;
		break;
	}

	// update trans
	*this += trans_update * game.time.getDelta();


	

}

void Player::render(Transform offset) const
{
	offset << *this;
	game.renderer.setColor(color::green);
	Rect::renderStatic(offset);
	renderChildren(offset);
}
