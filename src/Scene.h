#pragma once

#include "Object.h"
#include "Position2i.h"



enum struct scene_num {
	mainmenu,
	level,
	stats,
	options,
	credits,
	leveleditor,
};








struct Scene : virtual public Object {




	virtual ~Scene() {}

	bool load() override;

	virtual void render(Transform offset) const override;

	void setCamera(Transform camera_trans);

protected:
	void renderBG(SDL_Color col, Transform offset) const;




public:
	static double pixelToUnits(double pix);
	static Position pixelToPos(Position2i pos);
};


