#include "CargoShip.h"

void CargoShip::print() const
{
    cout << "Ship Name: " << getName() << endl
         << "Tonnage: " << tonnage << endl;
}