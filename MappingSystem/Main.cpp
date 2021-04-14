#include "Window.h"
#include "Sprite.h"
#include "Map.h"
#include "Robot.h"
#include "RobotController.h"

int main()
{
	Window* game = new Window("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	Map* map = new Map(game, "Assets/newLab.txt");
	Sprite* sprite = new Sprite("Assets/wall.png", game);
	Sprite* robotSprite = new Sprite("Assets/robot.png", game);
	Robot* robot = new Robot(game);
	RobotController* controller = new RobotController("Assets/testmap.txt");
	int xPos = 490;
	int yPos = 760;

	while (game->Running())
	{
		
		map->LoadMap(game, sprite);
		robot->RenderRobot(robotSprite);
		controller->RobotMovement(robot, map);
		
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