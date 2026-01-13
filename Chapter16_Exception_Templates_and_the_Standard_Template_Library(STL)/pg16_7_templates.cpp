/*
This program demonstrates the use of function templates in C++.
---------------------------------------------------------------
• A function template allows the same function to work with different data types.
• The compiler automatically generates ("instantiates") the function
  when it encounters a call with a specific type.
*/

#include <iostream>
#include <iomanip> // for setprecision, setw, fixed, showpoint

using namespace std;

// Template definition for the square function
// T can represent any data type (int, double, float, etc.)
template <class T>
T square(T num)
{
    return num * num;
}

int main()
{
    int userInt;
    double userDouble;

    cout << setprecision(5) << fixed << showpoint;

    cout << "Enter an integer: ";
    cin >> userInt;

    cout << "Enter a double: ";
    cin >> userDouble;

    // The compiler automatically generates two versions of square():
    //  - one for int
    //  - one for double
    cout << "\nSquare of integer: " << setw(5) << square(userInt) << endl;
    cout << "Square of double:  " << setw(5) << square(userDouble) << endl;

    return 0;
}

/*
Note:
-----
• A function template is only a "blueprint".
• It does not consume memory until the compiler encounters a specific call,
  such as square(5) or square(5.5).
• Each unique data type used in a call causes the compiler to generate
  a separate version of the function in memory (function instantiation).
*/