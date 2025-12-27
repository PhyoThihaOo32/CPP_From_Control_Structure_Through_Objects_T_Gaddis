#include <iostream>
#include "GasTank.h"

using namespace std;

int main()
{

    GasTank carTank(100);
    double carTankCapacity;
    cout << "Type the capacity of a car tank: ";
    cin >> carTankCapacity;

    cout << carTank.getGasLevel() << endl;

    return 0;
}
