#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship
{
private:
    int tonnage;

public:
    CargoShip()
    {
    }

    CargoShip(string name, string buildYear, int tonnage) : Ship(name, buildYear), tonnage(tonnage)
    {
    }

    void print() const override;
};

#endif