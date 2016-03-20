#include "Level.h"
#include "Game.h"


const char * filename_wall_img = "res\\wall.png";



struct Wall :virtual public Transform,virtual public Load,virtual public Render {
	Texture tex;
	Wall() { tex.name = filename_wall_img; }
	~Wall() {}
	bool load() override {
		return tex.load(filename_wall_img);
	}
	void unload() override {
		tex.unload();
	}
	void render(Transform offset) const override {
		offset << *this;
		tex.render(offset);
	}
};
Map::Map() {
	const int num_top = 28;
	const int num_sides = 16 - 2;
	const double wall_size = 9./16. - .06;
	const double left_offset = (game.w - (double(num_top)*wall_size)) / 2;
		//(((16./9.)*16.) - double(num_top)) / 2.;

	// generate top Walls
	for (int i = 0; i < num_top; ++i) {
		Wall* wall = new Wall();

		wall->pos.x = (i*wall_size) + left_offset;
		wall->pos.y = 0;
		wall->size *= wall_size;
		
		addLoad(wall);
		addRender(wall);
	}
	// generate bottom Walls
	for (int i = 0; i < num_top; ++i) {
		Wall* wall = new Wall();

		wall->pos.x = (i*wall_size) + left_offset;
		wall->pos.y = game.h - wall_size;
		wall->size *= wall_size;

		addLoad(wall);
		addRender(wall);
	}
	// generate left Walls
	// generate right Walls
}

void Map::render(Transform offset) const
{
	offset << *this;
	renderChildren(offset);
}






Level::Level() {
	addObject(&map);
}



void Level::input() {
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);

	inputChildren();
}
