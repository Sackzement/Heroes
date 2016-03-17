#pragma once




struct Load {
	virtual bool load() = 0;
	virtual void unload() = 0;
}; 