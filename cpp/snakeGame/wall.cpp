#include "wall.h"

extern unsigned char map[WIDTH][HEIGHT];

void Wall::PlaceWallOnMap()
{
    /* Top and down wall */
    for (int x = 0; x < WIDTH; x++)
    {
        map[x][0] = 'X';
        map[x][19] = 'X';
    }
    /* Left and right wall */
    for (int y = 0; y < HEIGHT; y++)
    {
        map[0][y] = 'X';
        map[19][y] = 'X';
    }
}
