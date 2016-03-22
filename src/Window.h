#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>



class Window {
	SDL_Window*  m_window;
public:


	virtual ~Window() {}
	int w, h;


	bool create();
	void destroy();

	operator SDL_Window* () const;

	void pullSize();



};



class Renderer {
	SDL_Renderer*  m_renderer;
public:

	virtual ~Renderer() {}

	bool create();
	void destroy();
	operator SDL_Renderer* () const;

	SDL_Color getColor();
	void setColor(SDL_Color col);
};