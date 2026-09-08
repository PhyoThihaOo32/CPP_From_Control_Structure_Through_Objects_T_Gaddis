/*
Creature Class

Creature class is a kind of point that move around - so it is the derived class of the point class.
*/

#ifndef CREATURE_H
#define CREATURE_H

#include "Point.h"

class Creature: public Point{
    public:
      
        void move();
        void move(direction );
        virtual void speak() = 0; // pure virtual function which make the creature class an abstract class
};

#endif