#ifndef _FOOD_H
#define _FOOD_H

#include "common.h"
#include <ctime>

class Food
{
private:
    Coordinate m_pos;
public:
    Food();
    ~Food();
    void RegenerateFood(unsigned int, unsigned int);
    void PlaceFoodOnMap();
};

#endif /* ifndef _FOOD_H */
