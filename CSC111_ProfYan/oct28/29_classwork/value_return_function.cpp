/*
This function return value.
*/

#include <iostream>

using namespace std;

double triangle_perimeter(double, double, double);
double triangle_perimeter();
double average(int, int, int);
void print_doubled_value(int);

int main()
{
    // double side1, side2, side3, perimeter1;
    // perimeter1 = triangle_perimeter(4, 5, 6);
    // cout << "Perimeter total: " << perimeter1 << endl;

    // cout << "Enter the sides: ";
    // cin >> side1 >> side2 >> side3;

    // perimeter1 = triangle_perimeter(side1, side2, side3);
    // cout << "Perimeter: " << perimeter1 << endl;

    int x = 5;

    cout << "In the main, x's value is " << x << endl;
    print_doubled_value(x);
    cout << "In the main, after the call, x's value is " << x << endl;

    return 0;
}

double triangle_perimeter(double side1, double side2, double side3)
{
    double perimeter; // local variables
    perimeter = side1 + side2 + side3;
    return perimeter; // return 1 value
}

double triangle_perimeter()
{
    double side1, side2, side3, perimeter;

    cout << "Enter side 1: ";
    cin >> side1;
    cout << "Enter side 2: ";
    cin >> side2;
    cout << "Enter side 3: ";
    cin >> side3;

    perimeter = side1 + side2 + side3;

    return perimeter;
}

double average(int num1, int num2, int num3)
{
    return ((num1 + num2 + num3) / 3.0);
}

void print_doubled_value(int x) // pass by value
{
    x *= 2;
    cout << "In the function, x is " << x << endl;
}
