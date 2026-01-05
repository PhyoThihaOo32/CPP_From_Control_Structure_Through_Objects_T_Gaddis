#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
using namespace std;

int main()
{
    Car car("Toyota", 2025, 10, 35000, 4);
    Truck truck("GMC", 2024, 15, 45000, "4WD");
    SUV suv("KIA", 2024, 6000, 25000, 7);

    cout << "=== Vehicle Inventory ===" << endl
         << endl;
    car.displayCar();
    truck.displayTruck();
    suv.displaySUV();

    return 0;
}