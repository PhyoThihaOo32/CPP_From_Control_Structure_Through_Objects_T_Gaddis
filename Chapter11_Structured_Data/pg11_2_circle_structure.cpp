/*
This program stores data about a circle in a structure.
It demonstrates returning a structure from a function and passing a structure to another function.
*/

#include <iostream>
#include <cmath>   // for pow()
#include <iomanip> // for setprecision()
using namespace std;

const double PI = 3.14159;

// Structure definition
struct Circle
{
    double diameter;
    double radius;
    double area;
};

// Function prototypes
Circle getCircle();
void circleInfo(const Circle &);

int main()
{
    // Create and initialize Circle objects by calling getCircle()
    Circle c1 = getCircle();
    Circle c2 = getCircle();

    // Display results
    cout << fixed << setprecision(2);

    cout << "\n----------------------------------------";
    cout << "\nCircle 1 Details:";
    cout << "\n----------------------------------------";
    circleInfo(c1);

    cout << "\n\n----------------------------------------";
    cout << "\nCircle 2 Details:";
    cout << "\n----------------------------------------";
    circleInfo(c2);

    cout << endl;
    return 0;
}

// Function to input diameter and compute radius and area
Circle getCircle()
{
    Circle temp;
    cout << "\nEnter the diameter of the circle: ";
    cin >> temp.diameter;

    temp.radius = temp.diameter / 2.0;
    temp.area = PI * pow(temp.radius, 2);

    return temp; // return the entire structure
}

// Function to display the data of a Circle structure
void circleInfo(const Circle &c)
{
    cout << "\nDiameter: " << c.diameter
         << "\nRadius:   " << c.radius
         << "\nArea:     " << c.area;
}