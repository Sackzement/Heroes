#pragma once
#include <SDL/SDL_events.h>
#include "Position2i.h"









const unsigned short num_buttons = 6;

class Mouse {

	Position2i m_pos;
	bool       m_did_move;
	Position2i m_dist_moved;
	bool       m_did_wheel_move;
	int        m_dist_wheel_moved;

	bool buttonDownMask[num_buttons] = {};
	bool buttonDownOnceMask[num_buttons] = {};
	bool buttonUpOnceMask[num_buttons] = {};


public:
	Mouse();
	virtual ~Mouse() {}

	inline Position2i getPos() const {
		return m_pos;
	}
	inline bool did_move() const
	{
		return m_did_move;
	}
	inline Position2i dist_moved() const {
		return m_dist_moved;
	}
	inline bool did_wheel_move() const
	{
		return m_did_wheel_move;
	}
	inline int dist_wheel_moved() const { 
		return m_dist_wheel_moved;
	}
	inline int getX() const {
		return m_pos.x;
	}
	inline int getY() const {
		return m_pos.y;
	}



	bool isButtonDown(Uint8 btn);
	bool isButtonUp(Uint8 btn);
	bool isButtonDownOnce(Uint8 btn);
	bool isButtonUpOnce(Uint8 btn);



	void processMouseMoveEvent(SDL_MouseMotionEvent ev);
	void processMouseButtonDownEvent(SDL_MouseButtonEvent ev);
	void processMouseButtonUpEvent(SDL_MouseButtonEvent ev);
	void processMouseWheelEvent(SDL_MouseWheelEvent ev);



	void reset();
};