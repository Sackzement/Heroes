
#include "Events.h"






Events::Events() :
	m_polledEvents(std::vector<SDL_Event>())
{}



void Events::pollEvents() {

	SDL_Event ev;

	m_polledEvents.clear();
	while (SDL_PollEvent(&ev))
		m_polledEvents.push_back(ev);
}

const std::vector<SDL_Event>& Events::getPolledEvents() const
{
	return m_polledEvents;
}



/*void InputManager::executePolledEvents() {

	size_t len = polledEvents.size();

	for (size_t i = 0; i < len; ++i) {

		//polledEvents[i].type
	}
}*/