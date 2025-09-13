/*
Relational Expression have higher precedence than the assignment operator
*/

#include <iostream>

int main()
{

    bool trueValue, falseValue;
    int x = 5, y = 10;

    trueValue = x < y;
    falseValue = x > y;

    std::cout << "True is: " << trueValue << std::endl;
    std::cout << "False if: " << falseValue << std::endl;

    return 0;
}