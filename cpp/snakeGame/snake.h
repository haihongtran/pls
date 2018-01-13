#ifndef _SNAKE_H
#define _SNAKE_H

#include "common.h"

#define LEN 3

typedef enum _Direction
{
    UP,     // 0
    DOWN,   // 1
    LEFT,   // 2
    RIGHT   // 3
} Direction;

class Snake
{
private:
    Coordinate m_headPos;
    VectorCoordinate m_bodyPos;
    unsigned int m_length;
    Direction m_direction;
public:
    Snake();
    ~Snake();

    void PlaceSnakeOnMap();
    Coordinate GetHead();
    VectorCoordinate GetBody();
    unsigned int GetLength();
    void IncreaseLength();
    Direction GetDirection();
    void SetDirection(Direction);
    void ChangeDirection(char);
    void Move();
};

#endif /* ifndef _SNAKE_H */
