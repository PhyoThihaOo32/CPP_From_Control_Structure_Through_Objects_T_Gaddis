// this is client demo file for car class

#include <iostream>
#include "Car.h"
#include <string>

using namespace std;

int main()
{

    Car myCar(2019, "Toyota");

    for (int i = 0; i < 5; i++)
    {
        myCar.accelerate();
        cout << "Current Speed: " << myCar.getSpeed() << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        myCar.decelerate();
        cout << "Current Speed: " << myCar.getSpeed() << endl;
    }

    return 0;
}