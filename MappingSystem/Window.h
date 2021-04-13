#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

class Window
{
private:
	int width;
	int height;

public:
	Window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Window();

	void HandleEvents();
	void Update();
	void Clear();
	void Render();
	void Clean();
	SDL_Renderer* GetRender();

	bool Running();

public:
	int GetWidth();
	int GetHeight();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

