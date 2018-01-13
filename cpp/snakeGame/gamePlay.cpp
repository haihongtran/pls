#include "gamePlay.h"

extern unsigned char map[WIDTH][HEIGHT];

bool GamePlay::SnakeHitWall(Coordinate snakeHeadPos)
{
    if (map[snakeHeadPos.x][snakeHeadPos.y] == 'X')
        return true;
    else
        return false;
}

bool GamePlay::SnakeHitSnake(Coordinate snakeHeadPos)
{
    if (map[snakeHeadPos.x][snakeHeadPos.y] == 'o')
        return true;
    else
        return false;
}

void GamePlay::CheckSnakeHitFood(Snake *snake, Food *food)
{
    if (map[(snake->GetHead()).x][(snake->GetHead()).y] == '*')
    {
        snake->IncreaseLength();
        food->RegenerateFood(WIDTH, HEIGHT);
    }
}
