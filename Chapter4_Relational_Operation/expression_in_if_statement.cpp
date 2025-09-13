/*
Relation expression has value 1 when true and 0 when false
But with if statment () - 0 is still false BUT any nonzero value is true.
*/

#include <iostream>

int main()
{

    int x = 0, y = 2;

    if (!(x = 0))
    {
        std::cout << "Zero mean False. Not Zero/Not False mean True." << std::endl;
    }

    std::cout << "The Reflection of Thin Line Between Truth and Falsity Inside The Mirror of Smoke." << std::endl;

    return 0;
}