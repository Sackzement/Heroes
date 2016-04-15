#include "Window.h"
#include <string>
#include "Log.h"
#include "Game.h"


int getNearestFactor(double aspX,double aspY, double w,double h){
    
    const double specified_size = w * h;
    
    int   i = 0;
    int ixi = 0;
    
    while (ixi < specified_size) {
        ++i; ixi = int((aspX*double(i)) * (aspY*double(i))); }
    
    if ( ixi - specified_size < specified_size - ((aspX*double(i-1)) * (aspY*double(i-1))) )
        return i;
    else
        return i-1;
    
    
    
}

Window::Window()
	: pointer(nullptr),
	position(),
	size(),
	transform()
{
}

bool Window::create() {

	if (pointer) {
		Log("\nWindow already exists, destroy first");
		return false;
	}

	// load settings from file
	// ...
	// else -> create default window with 2/3 screen size
    const double   win_frac       = 2./3.;
          SDL_Rect display = game.hardware.displays[0].bounds;
    
    int factor = getNearestFactor(game.w,game.h,double(display.w) * win_frac, double(display.w) * win_frac);
    
    SDL_Rect win;
    win.w = int(game.w * factor);
    win.h = int(game.h * factor);
    win.x = (display.w - win.w) / 2;
    win.y = (display.h - win.h) / 2;
    
	pointer = SDL_CreateWindow("Heroes", win.x, win.x, win.w, win.h, SDL_WINDOW_SHOWN);

	if (!pointer) {
		Log(SDL_GetError());
		return false;
	}

	updateAll();

	return true;
}
void Window::destroy() {
	SDL_DestroyWindow(pointer);  pointer = nullptr;

	position.nullify();
	size.nullify();
	flag = 0;

	transform.nullify();
}

SDL_Window* Window::getPointer() const {
	return pointer;
}

double Window::getScale() const
{
	return transform.scale.x;
}

Position2i Window::getPosition() const
{
	return position;
}

Size2i Window::getSize() const
{
	return size;
}

Uint32 Window::getFlag() const
{
	return flag;
}

void Window::updatePosition()
{
	int x, y;
	SDL_GetWindowPosition(pointer, &x, &y);

	position.set(x, y);
}

void Window::updateSize()
{
	int w, h;
	SDL_GetWindowSize(pointer, &w, &h);

	size.set(w, h);

	updateTransform();
}

void Window::updateFlag()
{
	Uint32 flag = SDL_GetWindowFlags(pointer);

	this->flag = flag;
}

void Window::updateAll()
{
	updatePosition();
	updateSize();
	updateFlag();
}

void Window::setPosition(int x, int y)
{
	SDL_SetWindowPosition(pointer, x, y);
	updateAll();
}

void Window::setSize(int w, int h)
{
	SDL_SetWindowSize(pointer, w, h);
	updateAll();
}

bool Window::isFullscreen() const
{
	return isFullscreenNormal() || isFullscreenFake();
}

bool Window::isFullscreenNormal() const
{
	return (flag & Fullscreen::normal) != 0;
}

bool Window::isFullscreenFake() const
{
	return (flag & Fullscreen::fake) != 0;
}

void Window::setFullscreen(Fullscreen var)
{
    switch (var) {
        case Fullscreen::off :
            SDL_SetWindowFullscreen(pointer, 0);
            SDL_SetWindowBordered(pointer, SDL_TRUE);
            setPosition(m_defaultPosSize.x, m_defaultPosSize.y);
            setSize(m_defaultPosSize.w, m_defaultPosSize.h);
            break;
        case Fullscreen::normal :
        case Fullscreen::fake :
            if (SDL_SetWindowFullscreen(pointer, var) != 0)
                Log(SDL_GetError());
            break;
        case Fullscreen::window :
            SDL_SetWindowFullscreen(pointer, 0);
            SDL_SetWindowBordered(pointer, SDL_FALSE);
            setPosition(0,0);
            setSize(game.hardware.displays[0].bounds.w, game.hardware.displays[0].bounds.h);
            break;
    }
    
	updateAll();
}

Transform Window::getTransform() const
{
	return transform;
}

void Window::updateTransform()
{
	transform.pos.x = double(size.w) * .5;
	transform.pos.y = double(size.h) * .5;

	transform.scale.x = double(size.w) / game.w;
	transform.scale.y = double(size.h) / game.h;

	if (transform.scale.x < transform.scale.y)
		transform.scale.y = transform.scale.x;
	else
		transform.scale.x = transform.scale.y;

}



void Window::updateDefaultPosSize() {
    
    SDL_Rect display = game.hardware.displays[0].bounds;
    
    int factor = getNearestFactor(game.w,game.h,double(display.w) * default_win_screen_frac, double(display.w) * default_win_screen_frac);
    
    m_defaultPosSize.w = int(game.w * factor);
    m_defaultPosSize.h = int(game.h * factor);
    m_defaultPosSize.x = (display.w - m_defaultPosSize.w) / 2;
    m_defaultPosSize.y = (display.h - m_defaultPosSize.h) / 2;
}









#include"game.h"

bool Renderer::create() {

	SDL_DestroyRenderer(m_renderer);

	m_renderer = SDL_GetRenderer(game.window.getPointer());
	SDL_DestroyRenderer(m_renderer);

	m_renderer = SDL_CreateRenderer(game.window.getPointer(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	if (!m_renderer) {
		Log(SDL_GetError());
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

SDL_Color Renderer::getColor()  {
	SDL_Color c;
	SDL_GetRenderDrawColor(m_renderer,&c.r,&c.g,&c.b,&c.a);
	return c;
}


void Renderer::setColor(SDL_Color col)  {
	SDL_SetRenderDrawColor(game.renderer, col.r, col.g, col.b, col.a);
}

void Renderer::clear()
{
	SDL_RenderClear(m_renderer);
}

SDL_Texture * Renderer::getTarget() const
{
	return SDL_GetRenderTarget(m_renderer);
}

void Renderer::setTarget(SDL_Texture * tex)
{
	if (SDL_SetRenderTarget(m_renderer,tex) != 0)
		Log(SDL_GetError());
}
