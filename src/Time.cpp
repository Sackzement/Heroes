
#include "Time.h"
#include <SDL/SDL_timer.h>


Time::Time()

	: m_msPassed(0),
	m_delta(0.),
	m_fps(60),
	m_fpsReal(60.),

	m_msPerFrame(1000. / double(m_fps)),
	m_delayTime(0)
{}

void    Time::setFps(Uint16 newFPS) {

	m_fps = newFPS;
	m_msPerFrame = 1000. / double(m_fps);
}

void    Time::resetDelay() {

	m_delayTime = m_msPassed;
}


void    Time::update() {

	Uint32 lastGameTime = m_msPassed;
	m_msPassed = SDL_GetTicks();

	double diff = double(m_msPassed - lastGameTime);
	m_delta = .001 * diff;
	m_fpsReal = 1000. / diff;
}

void    Time::delay() {

	Uint32 lastDelayTime = m_delayTime;
	m_delayTime = SDL_GetTicks();

	double diff = double(m_delayTime - lastDelayTime);

	if (diff < m_msPerFrame)
		SDL_Delay(Uint32(m_msPerFrame - diff));

	m_delayTime = SDL_GetTicks();
}

Uint32 Time::getMsPassed() {
	return m_msPassed;
}
double Time::getDelta() {
	return m_delta;
}
Uint16 Time::getFps() {
	return m_fps;
}
double Time::getFpsReal() {
	return m_fpsReal;
}