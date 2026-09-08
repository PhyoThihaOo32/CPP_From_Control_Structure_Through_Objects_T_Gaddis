/*
Dirt Class

Dirt Class is a kind of point that reacts when it is vaccumed.
It is derived class of the point class.
*/

#ifndef DIRT_H
#define DIRT_H

#include "Point.h"

class Dirt: public Point{
    private:
        bool gone;
    public:
        Dirt(); // constructor 
        void disappear(); // show message Poof on the console
};

#endif