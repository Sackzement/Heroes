#include "Keyboard.h"



bool Keyboard::isKeyDown(Key key) {
	return keyDownMask[key];
}
bool Keyboard::isKeyUp(Key key) {
	return !keyDownMask[key];
}
bool Keyboard::isKeyDownOnce(Key key) {
	return keyDownOnceMask[key];
}
bool Keyboard::isKeyUpOnce(Key key) {
	return keyUpOnceMask[key];
}

void Keyboard::processKeyDownEvent(SDL_KeyboardEvent keyEvent) {
	keyDownOnceMask[keyEvent.keysym.scancode] = true;
	keyDownMask[keyEvent.keysym.scancode] = true;
}
void Keyboard::processKeyUpEvent(SDL_KeyboardEvent keyEvent) {
	keyUpOnceMask[keyEvent.keysym.scancode] = true;
	keyDownMask[keyEvent.keysym.scancode] = false;
}

void Keyboard::resetOnceMasks() {
	for (Uint32 i = 0; i < num_keys; ++i) {
		keyDownOnceMask[i] = false;
		keyUpOnceMask[i] = false;
	}
}
void Keyboard::resetAll() {
	resetOnceMasks();
	for (Uint32 i = 0; i < num_keys; ++i)
		keyDownMask[i] = false;
}