#pragma once
#include "SDL.h"
#include "Window.h"

class Sprite
{
public:
	SDL_Surface* surface;
	SDL_Texture* tex;

	Window* window;

	const char* path;

	SDL_Rect destRect = { 1, 1, 42, 73 };
	SDL_Rect srcMap = { 1, 1, 900, 700 };


	//Sprite(Window* window);

	Sprite(const char* path, Window* window);
	~Sprite();

	void ChangeSprite(const char* path);
};