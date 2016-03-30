#include "Level.h"
#include "Game.h"
#include "Rect.h"
#include "Color.h"
#include <time.h>
#include "Collision.h"


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
	if (game.keyboard.isKeyDownOnce(Key::Q))
		game.switchToScene(scene_num::mainmenu);
	if (game.mouse.isButtonDownOnce(SDL_BUTTON_RIGHT))
		game.switchToScene(scene_num::mainmenu);

	if ( selected &&
	     game.mouse.isButtonDown(SDL_BUTTON_LEFT)  )  {
		
		Position2i pixel_offset = game.mouse.dist_moved();
		Position   unit_offset  = Position( pixel_offset.x,
								     		pixel_offset.y);

		unit_offset /= game.window.getScale();
		selected->pos += unit_offset;
	}

	// select obj with mouse
	if (game.mouse.isButtonDownOnce(SDL_BUTTON_LEFT)) {

		selected = nullptr;

		Transform mouse_trans = game.mouse.pos().to_Transform();
		mouse_trans.pos /= game.window.getScale();
		mouse_trans.pos.x -= game.w * .5;
		mouse_trans.pos.y -= game.h * .5;

		Transform mouse_trans_scene = mouse_trans;
		mouse_trans_scene << *this;

		// check coll  mouse -> child objs
		size_t len = renders.size();
		for (size_t i = 0; i < len; ++i) {
			Transform off = *this;  
			off << *renders[i];
			if ( mouse_trans_scene.checkCollision(off).type == coll_type::intersect )  {
				selected = renders[i];
				break;
			}
		}

		// check coll with scene
		if (!selected) {
			Transform mouse_trans = game.mouse.pos().to_Transform();
			mouse_trans.pos /= game.window.getScale();
			mouse_trans.pos.x -= game.w * .5;
			mouse_trans.pos.y -= game.h * .5;

			if (mouse_trans.checkCollision(*this).type == coll_type::intersect)
				selected = this;
		}
	}

	// mausrad scrollen
	if (selected) {
		selected->scale += double(game.mouse.getWheelMoved())*.1;
		if (selected->scale.x <= .1) selected->scale.x = .1;
		if (selected->scale.y <= .1) selected->scale.y = .1;
	}

	inputChildren();
}

void Level::update() {

	// move clouds
	size_t len = bg_clouds.size();

	for (size_t i = 0; i < len; ++i)  {
		Object* cloud = bg_clouds[i];
		cloud->pos.x -= 1. * game.time.getDelta();
		if (cloud->pos.x < -10.)
			cloud->pos.x += 20.;
	}

	updateChildren();

	checkCollision();
}

void Level::checkCollision()
{
	size_t len = walls.size();

	for (size_t i = 0; i < len; ++i) {

		Collision coll = player.checkCollision(*walls[i]);

		if ( coll.type == coll_type::intersect )  {


			// which side is smallest

			if (coll.scale.x < coll.scale.y) {// resolve left / right
				if (player.pos.x < coll.pos.x) // left
					player.pos.x -= coll.scale.x;
				else // right
					player.pos.x += coll.scale.x;
			}
			else { // resolve up down
				if (player.pos.y < coll.pos.y) {// up + reset fall speed
					player.pos.y -= coll.scale.y;
					player.trans_update.pos.y = 0;	}
				else // down
					player.pos.y += coll.scale.y;
			}


		}
	}
}

void Level::render(Transform offset) const {

	offset << *this;

	renderBG(color::sky_blue, offset);



	renderChildren(offset);
}






struct Wall :virtual public Object {
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
		cloud->scale.x = random( 2. ,4. );
		cloud->scale.y = random( 1. ,2. );

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
		wall->scale *= wall_size;
		
		walls.push_back(wall);

		addLoad(wall);
		addRender(wall);
	}
	// generate bottom Walls
	for (int i = 0; i < num_top; ++i) {
		Wall* wall = new Wall();

		wall->pos.x = -8. + (wall_size / 2) + (i*wall_size) + left_offset;
		wall->pos.y = 4.5 - (wall_size/2);
		wall->scale *= wall_size;

		walls.push_back(wall);

		addLoad(wall);
		addRender(wall);
	}
	// generate left Walls
	// generate right Walls


	return true;
}

