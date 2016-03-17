#include "Window.h"
#include <string>
#include "Log.h"


bool Window::create() {

	if (m_window)
		SDL_DestroyWindow(m_window);

	m_window = SDL_CreateWindow("Ducklight", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (!m_window) {
		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	pullSize();

	return true;
}
void Window::destroy() {
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	w = h = 0;
}

Window::operator SDL_Window* () const {
	return m_window;
}

void Window::pullSize() {
	SDL_GetWindowSize(m_window, &w, &h);
}
 


#include"game.h"

bool Renderer::create() {

	SDL_DestroyRenderer(m_renderer);

	m_renderer = SDL_GetRenderer(game.window);
	SDL_DestroyRenderer(m_renderer);

	m_renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	if (!m_renderer) {
		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	return true;
}
void Renderer::destroy() {
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
}

Renderer::operator SDL_Renderer* () const {
	return m_renderer;
}