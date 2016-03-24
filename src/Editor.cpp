#include "Editor.h"
#include "Game.h"





Editor::Editor() :
	visible(true)
{}







void Editor::input()
{
	if (game.keyboard.isKeyDownOnce(SDL_SCANCODE_E))
		visible = !visible;
}

void Editor::render(Transform offset) const
{
}
