/*
This program demonstrates that function templates can be overloaded.
----------------------------------------------------------------------
• Both functions have the same name (sum) but different parameter lists.
• The compiler determines which version to call based on the number of arguments.
• Each overloaded template must have its own `template <class T>` declaration.
*/

#include <iostream>
using namespace std;

// Function template: sum of two numbers
template <class T>
T sum(T num1, T num2)
{
    return num1 + num2;
}

// Overloaded function template: sum of three numbers
template <class T>
T sum(T num1, T num2, T num3)
{
    return num1 + num2 + num3;
}

int main()
{
    double num1, num2, num3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    cout << "\nSum of two numbers: " << sum(num1, num2) << endl;
    cout << "Sum of three numbers: " << sum(num1, num2, num3) << endl;

    return 0;
}

/*
Summary:
---------
• Templates can be overloaded like normal functions.
• Overloading is resolved by parameter count or types.
• Example instantiations created by compiler:
     sum<double>(double, double)
     sum<double>(double, double, double)
*/