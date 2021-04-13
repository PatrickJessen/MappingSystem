#include "Window.h"
#include "Sprite.h"
#include "Map.h"
int main()
{
	Window* game = new Window("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	Map* map = new Map(game, "Assets/newLab.txt");
	//map->texture = map->loadTexture(game->GetRender(), "Assets/labtiletest.bmp");
	Sprite* sprite = new Sprite("Assets/wall.png", game);

	while (game->Running())
	{
		map->LoadMap(game, sprite);
		game->Update();
		game->Clear();
	}
	game->Clean();
	//RenderMap();
	//RenderRobot();
	//if robot hits wall draw 1 in collisionfile // 1 represents a wall (cannot drive there)
	//else draw 0 in collisionfile // 0 represents free way to drive
	//Clear();
	return 0;
}