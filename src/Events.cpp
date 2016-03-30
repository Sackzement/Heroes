
#include "Events.h"






Events::Events() :
list(),
num(0)
{}



void Events::updateList() {

	// if cycle counter diferent
	list.clear();

	SDL_Event ev;
	while (SDL_PollEvent(&ev))
		list.push_back(ev);

	num = list.size();
}

const std::vector<SDL_Event>& Events::getList() const
{
	return list;
}

size_t Events::getNum() const
{
	return num;
}



/*void InputManager::executePolledEvents() {

	size_t len = polledEvents.size();

	for (size_t i = 0; i < len; ++i) {

		//polledEvents[i].type
	}
}*/