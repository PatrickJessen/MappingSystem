#include "Window.h"
#include "Sprite.h"
#include "Map.h"
int main()
{
	Window* game = new Window("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700, false);
	Map* map = new Map(game, "Assets/lab.map");
	map->texture = map->loadTexture(game->GetRender(), "Assets/LabTile.bmp");

	while (game->Running())
	{
		map->LoadMap(game);
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