#include "food.h"

extern unsigned char map[WIDTH][HEIGHT];

Food::Food(): m_pos(7,8)
{
    // cout << "Food constructor called." << endl;
}

Food::~Food()
{
    // cout << "Food destructor called." << endl;
}

void Food::RegenerateFood(unsigned int width, unsigned int height)
{
    Coordinate pos;
    srand(time(0));
    do {
        pos.x = (rand() % (width-1)) + 1;  /* between 1 and 19 */
        pos.y = (rand() % (height-1)) + 1; /* between 1 and 19 */
    } while (map[pos.x][pos.y] != ' ');
    m_pos = pos;
}

void Food::PlaceFoodOnMap()
{
    map[m_pos.x][m_pos.y] = '*';
}
