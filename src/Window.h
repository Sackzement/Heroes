#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include "Transform.h"
#include "Size2i.h"
#include "Position2i.h"
#include "Fullscreen.h"



class Window {

public:
    constexpr static const double default_win_screen_frac = 2./3.;
    
private:
	SDL_Window*  pointer;

	Position2i   position;
	Size2i       size;
	Uint32       flag;

	Transform    transform;



public:
	            Window();

	bool        create();
	void        destroy();


	SDL_Window* getPointer() const;

	Position2i  getPosition() const;
	Size2i      getSize() const;
	Uint32      getFlag() const;

	void        updatePosition();
	void        updateSize();

	void        setPosition(int x, int y);
	void        setSize(int w, int h);

	bool        isFullscreen() const;
	bool        isFullscreenNormal() const;
	bool        isFullscreenFake() const;

	void        setFullscreen(Fullscreen var);

	void        updateFlag();

	void        updateAll();


	// trans
	double      getScale() const;
	Transform   getTransform() const;
protected:
	void        updateTransform();


private:
    SDL_Rect m_defaultPosSize;
    void updateDefaultPosSize();
public:
    inline SDL_Rect getDefaultPosSize() const {
        return m_defaultPosSize;
    }
    
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

	void clear();

	SDL_Texture* getTarget() const;
	void         setTarget(SDL_Texture* tex);
};