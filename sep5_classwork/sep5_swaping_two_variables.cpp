/*
This program swap two variables
*/

#include <iostream>

int main()
{

    // Declariation and Initialization
    int x, y, temp;
    x = 10;
    y = 5;

    // Printing the initital Variables
    std::cout << "Before Swapping" << std::endl;
    std::cout << "x value: " << x << "\n"
              << "y value: " << y << std::endl;

    // Swapping Variable
    temp = x;
    x = y;
    y = temp;

    // Printing the result
    std::cout << "After Swapping" << std::endl;
    std::cout << "x value: " << x << "\n"
              << "y value: " << y << std::endl;

    std::cout << "What about temp: " << temp << std::endl;

    return 0;
}