#ifndef CAR_H
#define CAR_H

#include "Automobile.h"
#include <iostream>
using namespace std;

class Car : public Automobile
{
private:
    int doors;

public:
    Car() : Automobile(), doors(0) {}

    Car(string make, int year, int mileage, double price, int numDoors)
        : Automobile(make, year, mileage, price), doors(numDoors) {}

    int getDoors() const { return doors; }

    void displayCar() const
    {
        display();
        cout << "Doors: " << doors << endl
             << endl;
    }
};

#endif