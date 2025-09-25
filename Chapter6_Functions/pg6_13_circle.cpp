/*
This program calculates the area of a circle - has two function.
getradius() - get the radius from the user.
square() - will calculate the square of a number.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// function prototype
double getRadius();
double square(double);
double area_circle(const double, double);
ofstream creatFile(string);

int main()
{
    // constant of PI
    const double PI = 3.14159265358979323846;

    double radius,
        area;

    // create file
    ofstream circleFile = creatFile("circle.txt");

    // get radius
    // radius = getRadius();

    // calculate area = pi r^2
    area = area_circle(PI, getRadius());

    // print out the result
    cout << "Area of the circle is: " << area << endl;

    // write the result to the file
    circleFile << "Area of the circle is: " << area << endl;

    // close the file
    circleFile.close();

    return 0;
}

double getRadius()
{

    double radius;

    // ask radius from the user
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    return radius;
}

double square(double number)
{
    return (number * number);
}

double area_circle(const double PI, double radius)
{
    return PI * square(radius);
}

ofstream creatFile(string filename)
{
    ofstream outputFile(filename);
    return outputFile;
}