#include "RobotController.h"
#include <sys/stat.h>

RobotController::RobotController(const char* path)
{
    this->path = path;
    struct stat buf;
    if (stat(path, &buf) != -1)
    {
        std::ofstream os(path, std::ofstream::out);
        for (int r = 0; r < kRow; r++) {
            for (int c = 0; c < kCol; c++) {
                if (!os)
                {
                    level[r][c] = 0;
                }
                os << level[r][c];
            }
        }
    }
    else
    {
        std::ifstream fs(path, std::ifstream::in);
        for (int r = 0; r < kRow; r++) {
            for (int c = 0; c < kCol; c++) {
                fs >> level[r][c];
            }
        }
    }
}

void RobotController::RobotMovement(Robot* robot, Map* map)
{
    int random = rand() % 5;
    /*while (CanWalk(robot, map))
    {*/
        frameStart = SDL_GetTicks();
        if (random == 1)
        {
            robot->position.x++;
        }
        else if (random == 2)
        {
            robot->position.x--;
        }
        else if (random == 3)
        {
            robot->position.y++;
        }
        else if (random == 4)
        {
            robot->position.y--;
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    //}
    /*while (!CanWalk(robot, map))
    {
        frameStart = SDL_GetTicks();
        if (random == 1)
        {
            robot->position.x--;
        }
        else if (random == 2)
        {
            robot->position.x++;
        }
        else if (random == 3)
        {
            robot->position.y--;
        }
        else if (random == 4)
        {
            robot->position.y++;
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }*/
}

void RobotController::WriteFileCollision(Map* map)
{
    /*if (map->level[robot->pos][yPos] == 1)
    {
        std::ofstream os(path, std::ofstream::out);
        os << level[xPos][yPos];
    }*/
}

bool RobotController::CanWalk(Robot* robot, Map* map)
{
    //WriteFileCollision(map, xPos, yPos);
    if (level[robot->position.x][robot->position.y] == 0)
    {
        return true;
    }
    return false;
}