/*
This program asks the user to enter the length and width of a rectangle.
It calculate the area and displays the value on the screen
*/

#include <iostream>

using namespace std;

int main()
{

    double length, width, area;

    cout << "This program calculate the area of a rectangle in meter.\n";

    cout << "What is the length of the rectanlge? ";
    cin >> length;

    cout << "What is the width of the rectangle? ";
    cin >> width;

    // Calculate the area
    area = length * width;

    cout << "Area of the rectangle is " << area << "m3" << endl;

    return 0;
}