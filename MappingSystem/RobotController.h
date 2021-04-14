#pragma once
#include "Robot.h"
#include <fstream>
#include "Map.h"

class RobotController
{
public:
	RobotController(const char* path);

public:
	void RobotMovement(Robot* robot, Map* map);

public:
	int level[kRow][kCol];
	const char* path;

private:
	void WriteFileCollision(Map* map);
	bool CanWalk(Robot* robot, Map* map);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

};

