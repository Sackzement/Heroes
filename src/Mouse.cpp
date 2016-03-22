#include "Mouse.h"



Mouse::Mouse() : m_pos(), m_moved(false)
{
}

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

bool Mouse::moved()
{
	return m_moved;
}

void Mouse::processMouseMoveEvent(SDL_MouseMotionEvent ev) {
	m_pos.x = ev.x;
	m_pos.y = ev.y;

	m_moved = true;
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



void Mouse::reset()
{
	for (Uint32 i = 0; i < num_buttons; ++i) {
		buttonDownOnceMask[i] = false;
		buttonUpOnceMask[i] = false;
	}

	m_moved = false;

}
