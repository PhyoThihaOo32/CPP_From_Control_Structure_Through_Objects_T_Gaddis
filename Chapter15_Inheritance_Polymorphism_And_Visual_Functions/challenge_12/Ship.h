#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>

using namespace std;

class Ship
{
private:
    string name;
    string buildYear;

public:
    Ship() {};
    Ship(string name, string buildYear) : name(name), buildYear(buildYear)
    {
    }

    virtual ~Ship()
    {
    }

    // getter and setter
    string getName() const { return name; }
    string getBuildYear() { return buildYear; }

    virtual void print() const;
};

#endif