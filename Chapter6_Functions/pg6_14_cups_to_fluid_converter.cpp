/*
This program convert the cups to fluid ounces.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void showDisplay();
double getCups();            // get the number of cups from the user
double cupsToOunces(double); // convert cups to ounces

int main()
{
    // variable
    double number_cups,
        ounces;

    // set the numeric data format
    cout << setprecision(2) << showpoint << fixed;

    showDisplay();

    number_cups = getCups();

    ounces = cupsToOunces(number_cups);

    cout << number_cups << " number of cups is equivalent to " << ounces << " fluid ounces." << endl;

    return 0;
}

// display introductory screen what the program does to the user
void showDisplay()
{

    cout << "This program convert the cups to fluid ounces.\n"
         << "1 cup = 8 fluid ounces\n";
}

// get the number of cups from the user and return the value
double getCups()
{

    double number_cups;
    // get user input
    cout << "Enter the number of cups: ";
    cin >> number_cups;

    return number_cups;
}

// convert the number of cups to fluid ounces
double cupsToOunces(double number_cups)
{
    return number_cups * 8;
}
