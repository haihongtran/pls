#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

#include "common.h"
#include "snake.h"
#include "food.h"

class GamePlay
{
public:
    static bool SnakeHitWall(Coordinate );
    static bool SnakeHitSnake(Coordinate );
    static void CheckSnakeHitFood(Snake *, Food *);
};

#endif /* ifndef _GAMEPLAY_H */
