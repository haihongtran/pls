#include "common.h"
#include "snake.h"
#include "food.h"
#include "wall.h"
#include "gamePlay.h"
#include "main.h"

int main()
{
    Snake snake;
    Food food;
    Map::CleanMap();
    food.RegenerateFood(WIDTH, HEIGHT);
    Utility::CursorOff();
    while (1)
    {
        Map::CleanMap();
        Wall::PlaceWallOnMap();
        snake.PlaceSnakeOnMap();
        food.PlaceFoodOnMap();
        Utility::ClearScreen();
        Map::PrintMap();
        if (Utility::CheckKeyPressed())
        {
            snake.ChangeDirection(fgetc(stdin));
        }
        snake.Move();
        if (GamePlay::SnakeHitWall(snake.GetHead()))
        {
            usleep(500000);
            break;
        }
        else if (GamePlay::SnakeHitSnake(snake.GetHead()))
        {
            usleep(500000);
            break;
        }
        GamePlay::CheckSnakeHitFood(&snake, &food);
        usleep(500000);
    }
    cout << "GAME OVER!" << endl;
    cout << "Your snake's length is " << snake.GetLength() << "." << endl;
    Utility::CursorOn();
    return 0;
}
