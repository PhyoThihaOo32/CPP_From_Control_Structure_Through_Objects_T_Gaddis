#ifndef TRUCK_H
#define TRUCK_H

#include "Automobile.h"
#include <iostream>
using namespace std;

class Truck : public Automobile
{
private:
    string driveType;

public:
    Truck() : Automobile(), driveType(" ") {}

    Truck(string make, int year, int mileage, double price, string type)
        : Automobile(make, year, mileage, price), driveType(type) {}

    string getDriveType() const { return driveType; }

    void displayTruck() const
    {
        display();
        cout << "Drive Type: " << driveType << endl
             << endl;
    }
};

#endif