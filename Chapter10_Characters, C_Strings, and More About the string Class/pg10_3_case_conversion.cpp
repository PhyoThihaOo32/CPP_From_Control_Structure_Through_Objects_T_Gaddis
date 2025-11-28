/*
This program calculate the area of a circle.
*/

#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
    const double PI = 3.14159;
    double radius;
    char goAgain;

    cout << "This program calculate the radius of a circle." << endl;
    cout << setprecision(2) << showpoint << fixed;

    do
    {
        cout << "Enter the radius of the circle: ";
        cin >> radius;

        cout << "The area of the circle: " << (PI * radius * radius) << endl;

        // ask the user to do the calculation again or stop
        cout << "Calculate another (Y/N)? ";
        cin >> goAgain;

        // validate the input
        while (toupper(goAgain) != 'Y' && toupper(goAgain) != 'N')
        {
            cout << "Please enter the valid input." << endl;
            cin >> goAgain;
        }
    } while (toupper(goAgain) == 'Y');

    cout << "Thank you for using our program." << endl;

    return 0;
}