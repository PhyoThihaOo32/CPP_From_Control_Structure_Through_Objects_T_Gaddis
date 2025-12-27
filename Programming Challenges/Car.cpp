// implementation file for class car

#include "Car.h"
#include <string>

using namespace std;

Car::Car(int y, string m)
{
    yearModel = y;
    make = m;
    speed = 0;
}

int Car::getYearModel() const { return yearModel; }

string Car::getMake() const { return make; }

int Car::getSpeed() const { return speed; }

void Car::accelerate() { speed += 5; }

void Car::decelerate() { speed -= 5; }
