#ifndef WORLD_H
#define WORLD_H

#include "point.h"

class World
{
private:
    static const int COINS = 3;
    Point points[COINS]; // array of three points objects
public:
    void print() const;
    void set(int, int, int);
    Point getPoint(int) const;
};

#endif