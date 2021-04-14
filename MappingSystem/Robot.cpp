#include "Robot.h"

Robot::Robot(Window* window)
{
	this->window = window;
}

void Robot::RenderRobot(Sprite* sprite)
{
	SDL_RenderCopyEx(window->GetRender(), sprite->tex, NULL, &position, 0, 0, SDL_FLIP_NONE);
}
