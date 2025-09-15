/*
This program check if the user is qualify for low interest low
by checking if he/she is employed or recently graduated.
by using logical AND operator.
*/

#include <iostream>

using namespace std;

int main()
{

    char isEmployed, isGraduated;

    // Get user information
    cout << "Welcome to loan checker.\nYou must be employed and recently graduated\n"
         << "to qualify our loan program.\nPlease answer few questions."
         << "Are you employed?(y/n)" << endl;
    cin >> isEmployed;

    cout << "Are you recently graduated?(y/n)" << endl;
    cin >> isGraduated;

    if (isEmployed == 'y' && isGraduated == 'y')
    {
        cout << "Congragulation! You are pre-approved for our loan program." << endl;
    }
    else
    {
        cout << "You must be graduted from college in the past two years and\nYou must be employed to qualify." << endl;
    }

    return 0;
}