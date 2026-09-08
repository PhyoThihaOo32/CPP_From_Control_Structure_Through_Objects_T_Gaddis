/*
Robot Class 

A robot is a kind of creature that vacuums up dirt spots - so it is the derived class of the Creature class.
*/

#ifndef ROBOT_H
#define ROBOT_H

#include "Creature.h"

class Robot: public Creature{
    private:
        int num_vacuumed;
    public:
        Robot();
        void vacuum();
        bool busy(int);
        void speak(); // implementing abstract function
};

#endif