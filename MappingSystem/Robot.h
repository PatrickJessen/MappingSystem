#pragma once
#include "Sprite.h"
#include "Window.h"


class Robot
{
private:
	Window* window;

public:
	Robot(Window* window);

public:
	void RenderRobot(Sprite* sprite);

	SDL_Rect position = { 490, 760, 24, 24 }; //490, 760
private:
};

