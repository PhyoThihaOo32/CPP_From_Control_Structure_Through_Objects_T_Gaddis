/*
Two or more functions may have the same name, as long as their paramter lists are different - different set of parameters or parameters with different data types.
To distinguish the overloaded function with other function with the same name,
C++ use function signature - which is the name of the function and the data types of the function's parameters in proper order.
NOTE: function's return value is not part of the signature.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int square(int number);
double square(double number);

int main()
{
    int num_int;
    double num_double;

    cout << "Enter integer and double: ";
    cin >> num_int >> num_double;

    cout << "square of int: " << square(num_int)
         << "\nsquare of double: " << square(num_double) << endl;
}

int square(int number)
{
    return number * number;
}

double square(double number)
{
    return number * number;
}