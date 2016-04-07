#include "Mouse.h"



Mouse::Mouse() : 
	m_pos(),
	m_did_move(false),
	m_dist_moved(),
	m_did_wheel_move(false),
	m_dist_wheel_moved(0)
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



void Mouse::processMouseMoveEvent(SDL_MouseMotionEvent ev) {
	m_pos.x = ev.x;
	m_pos.y = ev.y;

	m_did_move = true;

	m_dist_moved.x = ev.xrel;
	m_dist_moved.y = ev.yrel;
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

void Mouse::processMouseWheelEvent(SDL_MouseWheelEvent ev)
{
	m_did_wheel_move = true;
	m_dist_wheel_moved = ev.y;
}



void Mouse::reset()
{
	for (Uint32 i = 0; i < num_buttons; ++i) {
		buttonDownOnceMask[i] = false;
		buttonUpOnceMask[i] = false;
	}

	m_did_move = false;
	m_dist_moved.x = 0;
	m_dist_moved.y = 0;

	m_did_wheel_move = false;
	m_dist_wheel_moved = 0;


}
