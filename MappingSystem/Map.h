#pragma once
#include "SDL.h"
#include "Window.h"
#include <fstream>
#include "Sprite.h"


static const int kRow = 39;//45;
static const int kCol = 36;//29;
static const int tileSize = 20;

class Map
{
public:
	Window* window;

	SDL_Texture* texture = nullptr;
	SDL_Rect dstRect;
	SDL_Rect srcRect;

	//SDL_Rect camera = { 24, 24, 24, 24 };
	SDL_Rect test = { 0, 0 }; //start position -1500, -1500

	int level[kRow][kCol];
	Map(Window* window, const char* path);
	~Map();

	void LoadMap(Window* window, Sprite* sprite);

	static SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath);

};