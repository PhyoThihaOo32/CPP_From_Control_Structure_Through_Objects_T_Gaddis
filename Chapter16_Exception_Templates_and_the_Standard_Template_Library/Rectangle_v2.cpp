#include "Rectangle_v2.h"

// Sets the rectangle's length; throws exception if negative
void Rectangle_v2::setLength(double len)
{
    if (len >= 0)
        length = len;
    else
        throw NegativeLength(); // custom exception type
}

// Sets the rectangle's width; throws exception if negative
void Rectangle_v2::setWidth(double w)
{
    if (w >= 0)
        width = w;
    else
        throw NegativeWidth(); // custom exception type
}