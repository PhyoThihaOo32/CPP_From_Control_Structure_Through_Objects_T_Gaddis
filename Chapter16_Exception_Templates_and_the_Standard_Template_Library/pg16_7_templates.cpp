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

template <class T>
T sum(T num1, T num2)
{
  return num1 + num2;
}

int main()
{
  int userInt;
  double userDouble;

  cout << setprecision(2) << fixed << showpoint;

  cout << "Enter an integer: ";
  cin >> userInt;

  cout << "Enter a double: ";
  cin >> userDouble;

  // The compiler automatically generates two versions of square():
  //  - one for int
  //  - one for double
  cout << left << setw(25) << "\nSquare of integer:"
       << right << setw(8) << square(userInt) << endl;

  cout << left << setw(25) << "Square of double:"
       << right << setw(8) << square(userDouble) << endl;

  cout << left << setw(25) << "Sum of Two Integers:"
       << right << setw(8) << sum(2, 2) << endl;

  cout << left << setw(25) << "Sum of Two Floats:"
       << right << setw(8) << sum(2.2, 2.2) << endl;

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