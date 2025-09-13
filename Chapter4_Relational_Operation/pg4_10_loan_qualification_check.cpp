/*
This program check if the user is qualify for low interest low
by checking if he/she is employed or recently graduated.
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

    if (isEmployed == 'y')
    {
        cout << "Are you recently graduated?(y/n)" << endl;
        cin >> isGraduated;
        if (isGraduated == 'y')
        {
            cout << "Congragulation! You are pre-approved for our loan program." << endl;
        }
        else
        {
            cout << "You must be graduted from college in the past two years to qualify." << endl;
        }
    }

    else
    {
        cout << "Sorry. You must be employed to qualify." << endl;
    }

    return 0;
}