#include "Game.h"
#include "Libs.h"
#include "MainMenu.h"
#include "Level.h"
#include "Stats.h"
#include "Options.h"
#include "Credits.h"
#include "LevelEditor.h"
#include "Color.h"
#include "Log.h"
//#include "HardwareInfo.h"

#include "Scene.h"

#include <sstream>
using std::ostringstream;
#include <iomanip>
using std::setprecision;




Game game;

const char * filename_font_file = "Zillah Modern Expanded.ttf";
const int font_size = 128;






Position pixelsToScenePos(Position2i pixels) {

	Transform units; units.nullify();
	units.pos = pixels;
	const Transform win_trans = game.window.getTransform();
	units.pos /= win_trans.scale.x;
	units.pos.x -= game.w * .5;
	units.pos.y -= game.h * .5;

	units << *game.scene;

	return units.pos;
}

Position pixelToScreenUnits(Position2i pixels) {

	Position unit; unit.nullify();
	unit = pixels;

	unit /= game.window.getScale();

	unit.x -= game.w * .5;
	unit.y -= game.h * .5;

	return unit;
}
Position screenUnitsToScene(Position p) {

	/*
	// rot
	const double initX = p.x,
		initY = p.y,

		cos_rot = cos(game.scene->rot*(pi / 180.)),
		sin_rot = sin(game.scene->rot*(pi / 180.));

	p.x = (cos_rot*initX) + (sin_rot*initY);
	p.y = (cos_rot*initY) + (sin_rot*initX);
	//p.y *= -1.;
	*/

	// scale & offset
	p -= game.scene->pos;
	// rotate
	const double initX = p.x,
		initY = p.y,

		cos_rot = cos(game.scene->rot*(pi / 180.)),
		sin_rot = sin(game.scene->rot*(pi / 180.));

	p.x = (cos_rot*initX) + (sin_rot*initY);
	p.y = (cos_rot*initY) - (sin_rot*initX);
	// scale
	p /= game.scene->scale;
	return p;
}

Position pixelDistToSceneDist(Position2i pixels)
{
	Position start, end;
	start = pixelToScreenUnits(Position2i(0,0));
	start = screenUnitsToScene(start);
	end   = pixelToScreenUnits(pixels);
	end   = screenUnitsToScene(end);

	return end - start;
}

Position pixelDistToScreenDist(Position2i pixels)
{
	Position start, end;
	start = pixelToScreenUnits(Position2i(0, 0));
	end = pixelToScreenUnits(pixels);

	return end - start;
}

std::string to_string_prec(const double num, const int prec)
{
	ostringstream out;
	out << fixed << setprecision(prec) << num;
	return out.str();
}

std::string getExtension(const std::string & str)
{
	std::string ret;
	const size_t len = str.size();

	if (len < 3)
		return ret;

	// searching for point position
	size_t pointPos = len - 2;
	bool pointFound = false;
	while(pointPos > 0)
	{
		if (str[pointPos] == '.') {
			pointFound = true;
			break;
		}
		--pointPos;
	}

	if (pointFound == false)
		return ret;

	// putting string after pointPos into return string
	for (size_t i = pointPos + 1; i < len; ++i)
		ret += str[i];

	return ret;
}




void Game::generatePath() {
	string str = string(argv[0]);
	size_t len = str.size();
	for (long long i = len - 1; i >= 0;--i) {
		if (str[i] == '\\' || str[i] == '/')  break;
		else str.pop_back();
	}
	path = str;
    
    path_res = path;
    
#ifdef __WINDOWS__
    path_res += "res\\";
#else
    path_res += "res/";
#endif
}

int Game::start(int argc, char** argv) {
	this->argc = argc;
	this->argv = argv;
	// generate path
	generatePath();

	Libs::init();
	hardware.update();
	window.create();
	renderer.create();

	// load font
	string str = path_res + filename_font_file;
	font = TTF_OpenFont(str.c_str(), font_size);
    
    loadCharTextures();


	scene = new MainMenu();
	scene->load();


	time.resetDelay();

	

	mainloop();

	renderer.destroy();
	window.destroy();
	Libs::quit();

	return 0;
}

void Game::pause() {
	state = game_states::paused;
}
void Game::unpause() {
	state = game_states::running;
}
void Game::togglePause() {
    
    if ( state != game_states::paused )
    state = game_states::paused;
else
    state = game_states::running;
}

void Game::quit() {
	state = game_states::quitting;
}

void Game::switchToScene(scene_num num) {


	switch (num) {
	case scene_num::mainmenu:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new MainMenu();
			scene->load();
		});
		break;
	case scene_num::level:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Level();
			scene->load();
		});
		break;
	case scene_num::stats:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Stats();
			scene->load();
		});
		break;
	case scene_num::options:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Options();
			scene->load();
		});
		break;
	case scene_num::credits:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new Credits();
			scene->load();
		});
		break;
	case scene_num::leveleditor:
		addScript([&]() {
			Scene* oldScene = scene;
			// new thread
			oldScene->unload();
			delete oldScene;

			scene = new LevelEditor();
			scene->load();
		});
		break;
	}
		
}

void Game::addScript(function<void()> func) {
	scripts.push_back(func);
}


void Game::loadCharTextures() {
    
    /*if (font == nullptr) { Log("Font == NULL,  can not create loadCharTexture surfaces");  return; }
    
    // creating all
    
    const char* prefix = "char_";
    
    char zero = '0';
    
    SDL_Surface* surf = TTF_RenderText_Solid( font, &zero, color::white);
    
    if (surf == nullptr) { Log(SDL_GetError());  continue; }
    
    SDL_Texture* sdlTex = SDL_CreateTextureFromSurface(game.renderer, surf);
    SDL_FreeSurface(surf);
    if (sdlTex == nullptr) { Log(SDL_GetError());  continue; }
    
    Texture tex;
    tex.texture = sdlTex;
    this->name = name; // need to prepare array with all texture names
    scale.x = width;
    scale.y = height;
    
    game.textures[name] = *this;
    */
    
}


void Game::mainloop() { while (state != game_states::quitting) {
	time.update();
	exeScripts();
	input();
	if (state != game_states::paused)
		update();
	render();
	time.delay();
}}

void Game::exeScripts()
{
	size_t len = scripts.size();

	for (size_t i = 0; i < len; ++i)
		scripts[i]();

	scripts.clear();
}


void Game::input() {
	
	keyboard.resetOnceMasks();
	mouse.reset();


	SDL_Event ev;
	while (SDL_PollEvent(&ev)) { switch (ev.type) {

	case SDL_QUIT:         state = game_states::quitting;  break;
	case SDL_WINDOWEVENT:  
		switch (ev.window.event) 
		{
		case SDL_WINDOWEVENT_RESIZED: window.updateAll(); break;
		case SDL_WINDOWEVENT_MOVED:   window.updateAll(); break;
		}
		break;
	case SDL_KEYDOWN:      keyboard.processKeyDownEvent(ev.key);  break;
	case SDL_KEYUP:        keyboard.processKeyUpEvent(ev.key);    break;

	case SDL_MOUSEMOTION:      mouse.processMouseMoveEvent(ev.motion);        break;
	case SDL_MOUSEBUTTONDOWN:  mouse.processMouseButtonDownEvent(ev.button);  break;
	case SDL_MOUSEBUTTONUP:    mouse.processMouseButtonUpEvent(ev.button);    break;
	case SDL_MOUSEWHEEL:       mouse.processMouseWheelEvent(ev.wheel);        break;
	}}
	

	// GLOBAL
    if (keyboard.isKeyDownOnce(Key::KP_1) || keyboard.isKeyDownOnce(Key::I) )
		window.setFullscreen(Fullscreen::normal);
	if (keyboard.isKeyDownOnce(Key::KP_2) || keyboard.isKeyDownOnce(Key::O) )
		window.setFullscreen(Fullscreen::fake);
	if (keyboard.isKeyDownOnce(Key::KP_0) || keyboard.isKeyDownOnce(Key::L) )
		window.setFullscreen(Fullscreen::off );
	if (keyboard.isKeyDownOnce(Key::KP_3) || keyboard.isKeyDownOnce(Key::P) )
		window.setFullscreen(Fullscreen::window);



	scene->input();

}


void Game::update() {
	scene->update();
}

void Game::render() {

	SDL_SetRenderTarget(game.renderer, nullptr);
	renderer.setColor(color::black);
	SDL_RenderClear(renderer);

	scene->render(window.getTransform());

	SDL_RenderPresent(renderer);
}




