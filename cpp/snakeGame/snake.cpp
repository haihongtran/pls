#include "snake.h"

extern unsigned char map[WIDTH][HEIGHT];

Snake::Snake(): m_headPos(WIDTH/2,HEIGHT/2),
                m_bodyPos({}),
                m_length(LEN),
                m_direction(RIGHT)
{
    Coordinate tmp;
    for(int i = 0; i < LEN-1;  i++)
    {
        tmp.x = m_headPos.x - i - 1;
        tmp.y = m_headPos.y;
        m_bodyPos.push_back(tmp);
    }
    // cout << "Snake constructor called." << endl;
}

Snake::~Snake()
{
    // cout << "Snake destructor called." << endl;
}

void Snake::PlaceSnakeOnMap()
{
    /* Place head on the map */
    map[m_headPos.x][m_headPos.y] = '%';

    /* Place body on the map */
    for (unsigned int i = 0; i < m_length - 1; i++)
    {
        {
            Coordinate body = m_bodyPos[i];
            map[body.x][body.y] = 'o';
        }
    }
}

Coordinate Snake::GetHead()
{
    return m_headPos;
}

VectorCoordinate Snake::GetBody()
{
    return m_bodyPos;
}

unsigned int Snake::GetLength()
{
    return m_length;
}

void Snake::IncreaseLength()
{
    m_bodyPos.resize(m_length);
    m_length++;
}

Direction Snake::GetDirection()
{
    return m_direction;
}

void Snake::SetDirection(Direction direction)
{
    m_direction = direction;
}

void Snake::ChangeDirection(char key)
{
    switch(GetDirection())
    {
        case UP:
        case DOWN:
            if (key == 'a')
            {
                SetDirection(LEFT);
                break;
            }
            else if (key == 'd')
            {
                SetDirection(RIGHT);
                break;
            }
            else
                break;
        case LEFT:
        case RIGHT:
            if (key == 'w')
            {
                SetDirection(UP);
                break;
            }
            else if (key == 's')
            {
                SetDirection(DOWN);
                break;
            }
            else
                break;
        default:
            break;
    }
}

void Snake::Move()
{
    /* Move BODY */
    for (int i = GetLength()-2; i > 0; i--)
    {
        m_bodyPos[i] = m_bodyPos[i-1];
    }
    m_bodyPos[0] = m_headPos;

    /* Move HEAD */
    switch(GetDirection())
    {
        case UP:
            m_headPos.y--;
            break;
        case DOWN:
            m_headPos.y++;
            break;
        case LEFT:
            m_headPos.x--;
            break;
        case RIGHT:
            m_headPos.x++;
            break;
        default:
            break;
    }
}
