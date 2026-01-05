#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>
#include <iostream>
using namespace std;

class Automobile
{
private:
    string make;
    int year;
    int mileage;
    double price;

public:
    Automobile() : make(" "), year(0), mileage(0), price(0.0) {}

    Automobile(string autoMake, int autoYear, int autoMileage, double autoPrice)
        : make(autoMake), year(autoYear), mileage(autoMileage), price(autoPrice) {}

    // Accessors
    string getMake() const { return make; }
    int getYear() const { return year; }
    int getMileage() const { return mileage; }
    double getPrice() const { return price; }

    // Virtual Display Function (can be overridden)
    virtual void display() const
    {
        cout << "Make: " << make << endl
             << "Model Year: " << year << endl
             << "Mileage: " << mileage << endl
             << "Price: $" << price << endl;
    }
};

#endif