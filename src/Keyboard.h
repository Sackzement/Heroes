#pragma once
#include <SDL/SDL_scancode.h>
#include <SDL/SDL_events.h>
#include "Key.h"


class Keyboard {

	bool keyDownMask[Key::num_keys] = {};
	bool keyDownOnceMask[Key::num_keys] = {};
	bool keyUpOnceMask[Key::num_keys] = {};



public:
	virtual ~Keyboard() {}
	bool isKeyDown(Key key);
	bool isKeyUp(Key key);
	bool isKeyDownOnce(Key key);
	bool isKeyUpOnce(Key key);

	void processKeyDownEvent(SDL_KeyboardEvent keyEvent);
	void processKeyUpEvent(SDL_KeyboardEvent keyEvent);

	void resetOnceMasks();

	void resetAll();
};