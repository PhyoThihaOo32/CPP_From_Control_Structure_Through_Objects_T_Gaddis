/*
This program demostrate how floating point round-off errors can make
equality operations unreliable
*/

#include <iostream>

int main()
{

    double a = 1.5, b = 1.5;

    a += 1e-20;

    if (a == b)
        std::cout << "a and b are equal." << std::endl;
    // if (a > b)
    //     std::cout << " a is greater than b." << std::endl;

    return 0;
}