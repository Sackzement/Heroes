#pragma once

#include <SDL/SDL_events.h>
#include <vector>


struct Events {

private:
	std::vector<SDL_Event> list;
	size_t                  num;



public:
	Events();

	void updateList();
	const std::vector<SDL_Event>& getList() const;
	void checkEvents();
	void executeEvents();
	size_t getNum() const;
	//void executePolledEvents();
};