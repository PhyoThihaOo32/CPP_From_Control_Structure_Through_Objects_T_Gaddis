/*
Cat Class

A Cat is kind of creature - so it is derived class of creature class.
*/

#ifndef CAT_H
#define CAT_H

#include "Creature.h"

class Cat: public Creature{
    public:
        void move();
        void move(direction );
        void speak();
};

#endif