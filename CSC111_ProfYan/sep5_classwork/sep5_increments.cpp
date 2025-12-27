/*
This program demostrate pre_increments/ post_increment
*/

#include <iostream>

int main()
{

    int x = 5;
    int y = 5;

    std::cout << "x is " << x << std::endl;
    std::cout << ++x << std::endl; // pre increment
    std::cout << "x is " << x << std::endl;

    std::cout << "y is " << y << std::endl;
    std::cout << y++ << std::endl; // pre increment
    std::cout << "y is " << y << std::endl;

    return 0;
}