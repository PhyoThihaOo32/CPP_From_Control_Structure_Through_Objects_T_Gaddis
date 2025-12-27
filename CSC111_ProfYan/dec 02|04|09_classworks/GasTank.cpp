#include "GasTank.h"

// write your solution here
GasTank::GasTank(double n)
{
    capacity = n;
    amount = 0;
}

void GasTank::addGas(double add)
{
    amount += add;
    if (amount > capacity)
        amount = capacity;
}

void GasTank::useGas(double use)
{
    amount -= use;
    if (amount < 0)
        amount = 0;
}

bool GasTank::isEmpty()
{
    if (amount < 0.1)
        return true;
    else
        return false;
}

bool GasTank::isFull()
{
    if (amount > capacity - 0.1)
        return true;
    else
        return false;
}

double GasTank::getGasLevel()
{
    return amount;
}

double GasTank::fillUp()
{
    double originalAmount = amount;
    amount = capacity;
    return amount - originalAmount;
}