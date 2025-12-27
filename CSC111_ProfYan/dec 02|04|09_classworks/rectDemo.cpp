#include <iostream>
#include "RectangleV3.h"

using namespace std;

int main()
{

    Rectangle r1, r2(5, 5, 5);
    int length, width, height;

    cout << "Enter the length, width and height: ";
    cin >> length >> width >> height;

    r1.setLength(length);
    r1.setWidth(width);
    r1.setHeight(height);

    cout << "Rectangle No.1" << endl;
    r1.showRectangle();

    cout << "Rectangle No.2" << endl;
    r2.showRectangle();

    if (r1.getArea() > r2.getArea())
    {
        cout << "Area of Rectangle 1 is greater than Area of Rectangle 2." << endl;
    }
    else if (r2.getArea() > r1.getArea())
    {
        cout << "Area of Rectangle 2 is greater than Area of Rectangle 1." << endl;
    }
    else
    {
        cout << "Rectangle 1 and Rectangle 2 has same area." << endl;
    }

    return 0;
}