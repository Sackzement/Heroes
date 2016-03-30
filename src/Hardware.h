#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include <string>
#include <vector>


class Display  {
public:
    int                idx;
    std::string        name;
    SDL_Rect           bounds;
	int                dpi;

    int                numModes;
std::vector<SDL_DisplayMode>  modes;

SDL_DisplayMode curr_mode;
SDL_DisplayMode curr_mode_desk;

	void updateByIdx(int newNum);
    SDL_DisplayMode getLargesMode();
};

class Hardware  {
public:
	std::string platform;
	int numCPUs;
	int CPUcacheLineSize;   // i think thats bit   (32/64)
	int RAM;

    int numVideoDrivers;
    int numDisplays;
    int numRenderDrivers;
    
	std::vector<std::string>  drivers;
	std::vector<Display>  displays;
	std::vector<SDL_RendererInfo>  renderers;

	std::string curr_driver = "";


	void update();
    
};