#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship
{
private:
    int numPassenger;

public:
    CruiseShip()
    {
    }

    CruiseShip(string name, string buildYear, int numPassenger) : Ship(name, buildYear), numPassenger(numPassenger)
    {
    }

    ~CruiseShip() override
    {
    }

    // getter and setter
    void setNumPassenger(int num)
    {
        numPassenger = num;
    }

    int getNumPassenger() const { return numPassenger; }

    void print() const override;
};

#endif