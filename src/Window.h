#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>



class Window {
	SDL_Window*  m_window;
public:
	int w, h;


	bool create();
	void destroy();

	operator SDL_Window* () const;

	void pullSize();



};



struct Renderer {
	SDL_Renderer*  m_renderer;
public:
	bool create();
	void destroy();
	operator SDL_Renderer* () const;
};