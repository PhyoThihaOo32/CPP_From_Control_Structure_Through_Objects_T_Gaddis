// Clocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "clockType.h"
using namespace std;

int main()
{

    cout << "Exercies 1.1.1 Using clockType class" << endl;
    clockType myClock;
    clockType bcnClock;
    int h, m, s;
    cout << "Enter hour: ";
    cin >> h;
    cout << "\nEnter minute: ";
    cin >> m;
    cout << "\nEnter seconds: ";
    cin >> s;

    myClock.setTime(h, m, s);

    bcnClock.setTime(h + 6, m, s);

    cout << "2 clocks compare is " << bcnClock.equalTime(myClock) << endl;

    cout << " My Clock Time : ";
    myClock.printTime();
    cout << endl;

    for (int x = 0; x < 6; x++)
        bcnClock.incrementHours();

    cout << " BCN Clock Time: ";
    bcnClock.printTime();
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file