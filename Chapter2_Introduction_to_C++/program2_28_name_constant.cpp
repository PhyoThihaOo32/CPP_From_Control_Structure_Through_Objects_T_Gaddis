/*
A named constant is a variable whose value cannot change once it is set.
You declare it using the const keyword.
The const keyword is a qualifier that tells the compiler to make the variable read-only.
*/

#include <iostream>

int main()
{

    // constants
    const double PI = 3.14159;
    const double DIAMETER = 10.0;

    // variable to hold the constant
    double circumference;

    // Calculate the circumference
    circumference = PI * DIAMETER;

    // Display the circumference
    std::cout << "The circumference is: " << circumference << std::endl;

    return 0;
}