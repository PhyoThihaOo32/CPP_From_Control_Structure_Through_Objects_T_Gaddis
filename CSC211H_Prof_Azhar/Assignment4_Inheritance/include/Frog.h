#ifndef FROG_H
#define FROG_H

#include "Creature.h"
#include <iostream>

using namespace std;

class Frog: public Creature{
    public:
        Frog(): Creature(){}

        void move();
        void speak() override;
};

#endif