/*
Point Class

This class has a 2D (x,y) coordinate and 
Functions that supprt setting, reporting printing the co-ordinates.
*/

#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <time.h>

enum direction {north, east, south, west};
const int WORLD_SIZE = 5;
const int MAX_SPOTS  = 3;


class Point{
    private:
        int x, y;
    public:
        Point();
        Point(int, int);
        // accessor functions
        int getX() const;
        int getY() const;

        // mutator functions
        void set(int, int);

        void print()const;
};

#endif