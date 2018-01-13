#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <vector>

#define WIDTH 20
#define HEIGHT 20
#define SPEED 500000

using namespace std;

typedef struct coordinate
{
    unsigned int x;
    unsigned int y;
    coordinate(unsigned int x = 1, unsigned int y = 1): x(x), y(y) {}
} Coordinate;

typedef std::vector<Coordinate> VectorCoordinate;

class Map
{
public:
    static void CleanMap();
    static void PrintMap();
};

class Utility
{
public:
    static void ClearScreen();
    static void CursorOff();
    static void CursorOn();
    static int  CheckKeyPressed();
};

#endif /* ifndef _COMMON_H */
