#pragma once
#include <SDL/SDL_scancode.h>
#include <SDL/SDL_events.h>

typedef SDL_Scancode Key;
const unsigned short num_keys = 512;

class Keyboard {

	bool keyDownMask[num_keys] = {};
	bool keyDownOnceMask[num_keys] = {};
	bool keyUpOnceMask[num_keys] = {};



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