#ifndef SUV_H
#define SUV_H

#include "Automobile.h"
#include <iostream>
using namespace std;

class SUV : public Automobile
{
private:
    int passCapacity;

public:
    SUV() : Automobile(), passCapacity(0) {}

    SUV(string make, int year, int mileage, double price, int capacity)
        : Automobile(make, year, mileage, price), passCapacity(capacity) {}

    int getPassCapacity() const { return passCapacity; }

    void displaySUV() const
    {
        display();
        cout << "Passenger Capacity: " << passCapacity << endl
             << endl;
    }
};

#endif