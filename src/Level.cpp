#include "Level.h"
#include "Game.h"
#include "Rect.h"
#include "Color.h"
#include <time.h>


const char * filename_wall_img = "res\\wall.png";
const char * filename_circle_img = "res\\cloud_circle.png";


double random(double from, double to) {
	double d = (double)rand() / (double)RAND_MAX;
	return from + (d * (to - from));
}
double random(double from, double to, Uint64 precision) {

	 double d = double(rand() % precision);
	return from + (d * (to - from));
}


Level::Level()
{
	init_bg_clouds();
	init_bg_walls();
	addObject(&player);

}

void Level::input() {
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_Q))
		game.switchToScene(scene_num::mainmenu);

	inputChildren();
}

void Level::update() {

	// move clouds
	size_t len = bg_clouds.size();
	for (size_t i = 0; i < len; ++i) {
		Object* cloud = bg_clouds[i];
		cloud->pos.x -= 1. * game.time.getDelta();
		if (cloud->pos.x < -10.)
			cloud->pos.x += 20.;
	}

	updateChildren();
}

void Level::render() const {

	renderBG();

	renderChildren(*this);
}

void Level::renderBG() const {

	game.renderer.setColor(color::sky_blue);
	Transform scene_trans = *this;
	scene_trans.size.w *= game.w;
	scene_trans.size.h *= game.h;
	Rect::renderStatic(scene_trans);
}




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

bool Level::init_bg_clouds()
{
	srand((unsigned int)time(NULL));

	const int num_clouds = 20;
	for (int i = 0; i < num_clouds; ++i) {

		Object* cloud = new Object();

		Texture* tex = new Texture();
		tex->name = filename_circle_img;
		cloud->addLoad(tex);
		cloud->addRender(tex);

		cloud->pos.x  = random(-10. ,10.);
		cloud->pos.y  = random(-3.5,1.5);
		cloud->size.w = random( 2. ,4. );
		cloud->size.h = random( 1. ,2. );

		cloud->addType(obj_type::load | obj_type::render);
		bg_clouds.push_back(cloud);
		//addLoad(cloud);
		//addRender(cloud);
		addObject(cloud);
	}

	return true;
}

bool Level::init_bg_walls() {
	const int num_top = 28;
	const int num_sides = 16 - 2;
	const double wall_size = 9./16. - .06;
	const double left_offset = (game.w - (double(num_top)*wall_size)) / 2;

	// generate top Walls
	for (int i = 0; i < num_top; ++i) {
		Wall* wall = new Wall();

		wall->pos.x = -8. + (wall_size / 2) + (i*wall_size) + left_offset;
		wall->pos.y = -4.5 + (wall_size/2);
		wall->size *= wall_size;
		
		addLoad(wall);
		addRender(wall);
	}
	// generate bottom Walls
	for (int i = 0; i < num_top; ++i) {
		Wall* wall = new Wall();

		wall->pos.x = -8. + (wall_size / 2) + (i*wall_size) + left_offset;
		wall->pos.y = 4.5 - (wall_size/2);
		wall->size *= wall_size;

		addLoad(wall);
		addRender(wall);
	}
	// generate left Walls
	// generate right Walls


	return true;
}

