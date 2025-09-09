/*
This program demonstrates integer overflow and underflow
This program can be used to see how your system handles floating point overflow and underflow
*/

#include <iostream>

using namespace std;

int main()
{

    // testVar is initialized with the maximum value for a short
    short testVar = 32767;
    float test;

    // Display testVar
    cout << testVar << endl;

    // Add 1 to make it overflow
    testVar += 1;
    cout << "Overflow: " << testVar << endl;

    // Substract 1 to make it underflow
    testVar = -32768;
    testVar = testVar - 1;
    cout << "Underflow: " << testVar << endl;

        // Testing how the system handle the overflow and underflow

    test = 2.0e38 * 1000; // should overflow test
    cout << "Overflow test: " << test << endl;

    test = 2.0e-38 / 2.0e38; // should underflow test
    cout << "Underflow test: " << test << endl;

    return 0;
}