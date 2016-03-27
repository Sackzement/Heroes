#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include "Transform.h"



class Window {
	SDL_Window*  m_window;
public:

	int w, h;
	Transform offset;


	operator SDL_Window* () const;
	virtual ~Window() {}
	bool create();
	void destroy();

	void pullSize();
	void update_offset();


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