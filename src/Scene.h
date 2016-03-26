#pragma once

#include "Object.h"
#include "Position2i.h"



enum struct scene_num {
	mainmenu,
	level,
	stats,
	options,
	credits,
};


struct Scene : virtual public Object {

private:
	static double scale;
public:
	inline static double getScale() { return scale; }
	static void rescale();

	static double pixelToUnits(double pix);
	static Position pixelToPos(Position2i pos);


	Scene();
	virtual ~Scene() {}

	bool load() override;

	virtual void render() const;
	using Object::render;
	void         renderBG(SDL_Color col) const;

};


