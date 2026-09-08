#include "Rectangle_v1.h"

// Sets length; throws exception if value is negative
void Rectangle_v1::setLength(double len)
{
    if (len >= 0)
        length = len;
    else
        throw NegativeValue();
}

// Sets width; throws exception if value is negative
void Rectangle_v1::setWidth(double w)
{
    if (w >= 0)
        width = w;
    else
        throw NegativeValue();
}