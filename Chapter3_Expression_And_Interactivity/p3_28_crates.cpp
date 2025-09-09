/*
A program that calculate the volume(in cubic feet), cost, price and profit of any crate
*/

#include <iostream>
#include <iomanip> // The <iomanip> header stands for “input/output manipulators”. It allows you to format the output of std::cout more precisely.

using namespace std;

int main()
{

    // Constant for costs and amount charge
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.50;

    // Declaring the variables
    double length, // crate length
        width,     // crate width
        height,    // crate height
        volume,    // crate volume
        cost,      // cost to build the crate
        charge,    // amount to charge the customer
        profit;    // profit made

    // Getting customer input

    cout << "Welcome. Please Enter the dimensions(in foot) and we will give you the price for the crate." << endl;
    cout << "Enter length:\t";
    cin >> length;
    cout << "Enter width:\t";
    cin >> width;
    cout << "Enter height:\t";
    cin >> height;

    // Formatting the data output
    cout << setprecision(2) << fixed << showpoint;

    // Calcuate the volume, cost and profit
    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge - cost;

    // Showing the calculated date

    cout << "Thank you for your inquire. Please see the result as follows:" << endl;
    cout << "Total Volume of the crate is " << volume << endl;
    cout << "It will cost " << cost << "$." << endl;
    cout << "We will charge you " << charge << " $." << endl;
    cout << "We made " << profit << "$ profit." << endl;
}