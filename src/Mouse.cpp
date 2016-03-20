#include "Mouse.h"



bool Mouse::isButtonDown(Uint8 btn) {
	return buttonDownMask[btn];
}

bool Mouse::isButtonUp(Uint8 btn) {
	return !buttonDownMask[btn];
}

bool Mouse::isButtonDownOnce(Uint8 btn) {
	return buttonDownOnceMask[btn];
}

bool Mouse::isButtonUpOnce(Uint8 btn) {
	return buttonUpOnceMask[btn];
}

void Mouse::processMouseMoveEvent(SDL_MouseMotionEvent ev) {
	m_pos.x = ev.x;
	m_pos.y = ev.y;
}



void Mouse::processMouseButtonDownEvent(SDL_MouseButtonEvent ev)
{
	buttonDownOnceMask[ev.button] = true;
	buttonDownMask[ev.button] = true;
}

void Mouse::processMouseButtonUpEvent(SDL_MouseButtonEvent ev)
{
	buttonUpOnceMask[ev.button] = true;
	buttonDownMask[ev.button] = false;
}



void Mouse::resetOnceMasks()
{
	for (Uint32 i = 0; i < num_buttons; ++i) {
		buttonDownOnceMask[i] = false;
		buttonUpOnceMask[i] = false;
	}
}
