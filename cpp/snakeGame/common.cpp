#include "common.h"

extern unsigned char map[WIDTH][HEIGHT];

void Map::CleanMap()
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
            map[x][y] = ' ';
    }
}

void Map::PrintMap()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            cout << map[x][y];
        }
        cout << endl;
    }
}

void Utility::ClearScreen()
{
    system("clear");
}

void Utility::CursorOff()
{
    system("setterm -cursor off");
}

void Utility::CursorOn()
{
    system("setterm -cursor on");
}

int Utility::CheckKeyPressed()
{
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
