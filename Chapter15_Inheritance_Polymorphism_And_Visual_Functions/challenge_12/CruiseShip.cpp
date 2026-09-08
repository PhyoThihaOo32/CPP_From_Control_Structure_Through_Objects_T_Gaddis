#include "CruiseShip.h"

void CruiseShip::print() const
{
    cout << "Ship Name: " << getName() << endl
         << "Number of Passenger: " << numPassenger << endl;
}