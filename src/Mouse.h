#pragma once
#include <SDL/SDL_events.h>



struct Position2i {
	int x=0, y=0;
};






const unsigned short num_buttons = 6;

class Mouse {

	Position2i m_pos;
	bool buttonDownMask[num_buttons] = {};
	bool buttonDownOnceMask[num_buttons] = {};
	bool buttonUpOnceMask[num_buttons] = {};


public:
	virtual ~Mouse() {}

	inline Position2i pos() const {
		return m_pos;
	}
	inline int x() const {
		return m_pos.x;
	}
	inline int y() const {
		return m_pos.y;
	}

	bool isButtonDown(Uint8 btn);
	bool isButtonUp(Uint8 btn);
	bool isButtonDownOnce(Uint8 btn);
	bool isButtonUpOnce(Uint8 btn);



	void processMouseMoveEvent(SDL_MouseMotionEvent ev);
	void processMouseButtonDownEvent(SDL_MouseButtonEvent ev);
	void processMouseButtonUpEvent(SDL_MouseButtonEvent ev);



	void resetOnceMasks();
};