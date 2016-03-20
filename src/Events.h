#pragma once

#include <SDL/SDL_events.h>
#include <vector>


struct Events {
private:
	std::vector<SDL_Event> m_polledEvents;
public:
	Events();

	virtual ~Events() {}
	void pollEvents();
	const std::vector<SDL_Event>& getPolledEvents() const;
	//void executePolledEvents();
};