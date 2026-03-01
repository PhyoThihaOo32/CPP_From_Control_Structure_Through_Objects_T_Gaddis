#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

enum orientation_type
{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST

};

class Robot
{
private:
    Point point;
    orientation_type direction;

public:
    void init();
    void print() const;
    void setOrientation(orientation_type);

    Point getPoint() const;

    bool forward();

    void turnCW();
    void turnAntiCW();

    bool eastEnd();
    bool westEnd();
    bool northEnd();
    bool southEnd();

    void zig();
    void zag();
};

#endif
