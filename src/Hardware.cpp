#include "Hardware.h"
#include <SDL/SDL_render.h>






void Display::updateByIdx(int newIdx)
{
	idx = newIdx;
    name      = SDL_GetDisplayName(idx);
	SDL_GetDisplayBounds(idx, &bounds);
	dpi = SDL_GetDisplayDPI(idx, nullptr, nullptr, nullptr);
	numModes = SDL_GetNumDisplayModes(idx);
    
    modes.clear();
    
    for (int i=0; i<numModes; ++i)  {
        modes.push_back(SDL_DisplayMode());
		SDL_GetDisplayMode(idx, i, &(modes.back()));
		SDL_GetCurrentDisplayMode(idx, &curr_mode);
		SDL_GetDesktopDisplayMode(idx, &curr_mode_desk);
    }
}



SDL_DisplayMode Display::getLargesMode()
{
    
    SDL_DisplayMode ret = SDL_DisplayMode();
    
    for (int i=0; i<int(modes.size()); ++i)  {
        
        if ( modes[i].w > ret.w )
            ret = modes[i];
    }
    
    return ret;
}




#include <SDL/SDL_cpuinfo.h>


void Hardware::update()
{
	platform = SDL_GetPlatform();
	numCPUs = SDL_GetCPUCount();
	CPUcacheLineSize = SDL_GetCPUCacheLineSize();
	RAM = SDL_GetSystemRAM();


	numVideoDrivers = SDL_GetNumVideoDrivers();
	numDisplays = SDL_GetNumVideoDisplays();
	numRenderDrivers = SDL_GetNumRenderDrivers();

	drivers.clear();
	for (int i = 0; i < numVideoDrivers; ++i) {
		drivers.push_back(SDL_GetVideoDriver(i));
	}

	displays.clear();
    for (int i=0; i<numDisplays; ++i)  {
		displays.push_back(Display());
		displays.back().updateByIdx(i);
    }

	curr_driver = SDL_GetCurrentVideoDriver();

	renderers.clear();
	for (int i = 0; i < numRenderDrivers; ++i) {
		renderers.push_back(SDL_RendererInfo());
		SDL_RendererInfo & re = renderers.back();
		SDL_GetRenderDriverInfo(i, &re);
	}

	
}





