/*
The setprecision manipulator in C++ is used to control the number of digits displayed for floating-point numbers (like float or double), either as:
    •	total significant digits (default), or
    •	fixed number of digits after the decimal (when used with fixed)
*/

#include <iostream>
#include <iomanip> // iomanip stands for “Input/Output Manipulators”

using namespace std;

int main()
{

    double quotient, number1 = 132.645, number2 = 23.987;

    quotient = number1 / number2;

    cout << quotient << endl;
    cout << setprecision(5) << quotient << endl;
    cout << setprecision(100) << quotient << endl;
}

/*
While there’s no hardcoded max limit on what you can pass to setprecision(), the maximum useful precision depends on the type:
    •	float: ~7 digits
    •	double: ~15 digits
    •	long double: ~18–21+ digits

 Key Notes:
    •	You can pass a much higher value to setprecision(), like setprecision(100), but only the accurate digits (depending on the type) will matter — the rest are just noise.
    •	Beyond the max precision of the type, you’re just printing garbage decimals that aren’t actually stored accurately.
*/