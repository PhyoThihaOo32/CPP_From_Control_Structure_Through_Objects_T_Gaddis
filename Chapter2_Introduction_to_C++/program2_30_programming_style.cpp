/*
Programming style is the way code is written to make it easy to read, understand, and maintain.

It includes:
    •	Clear variable names 
    •	Consistent indentation and spacing 
    •	Comments that explain logic 
    •	Organized structure and formatting 
*/

#include <iostream>

int main()
{

    double shares = 220.0;
    double avgPrices = 14.67;

    std::cout << "There were " << shares << " shares sold at $"
              << avgPrices << " per shares.\n";

    return 0;
}