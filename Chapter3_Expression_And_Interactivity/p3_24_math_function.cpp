/*
abs  -  y = abs(x);     // return intergers
exp  -  y = exp(x);     // return type and arguments are doubles
fmod -  y = fmod(x,z);  // return double and arguments are doubles - works like a modulus operator
sqrt -  y = sqrt(x);    // return type and arguments are doubles
*/

/*
This function calculate the length of hypotenuse.
*/

#include <iostream>
#include <iomanip> // for setprecision
#include <cmath>   // for math functions

using namespace std;

int main()
{

    double side_a, side_b, hypotenuse;

    cout << "Enter the length of the side a:\t ";
    cin >> side_a;

    cout << "Enter the length of the side b:\t ";
    cin >> side_b;

    hypotenuse = sqrt(pow(side_a, 2) + pow(side_b, 2));
    cout << "The length of the hypotenuse is: "
         << setprecision(4) << hypotenuse << endl;

    return 0;
}