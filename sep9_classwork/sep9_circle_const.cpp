/*
This program is about Constants.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    const double PI = 3.14159265359;
    double diameter, radius, circumference, area;

    cout << "What is the circle diameter in meter?" << endl;
    cin >> diameter;

    // Calculate radius
    radius = diameter / 2;

    // Calculate circumference
    circumference = 2 * PI * radius;

    // Calculate area
    area = PI * pow(radius, 2.0);

    // Display the result
    cout << setprecision(3) << fixed;
    cout << "Radius: " << radius << " m" << endl;
    cout << "Circumference: " << circumference << " m3" << endl;
    cout << "Area: " << area << " m2" << endl;

    // default decimal place is 6 is C++

    return 0;
}