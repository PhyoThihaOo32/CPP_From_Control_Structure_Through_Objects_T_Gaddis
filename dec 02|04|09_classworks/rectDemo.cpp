#include <iostream>
#include "RectangleV3.h"

using namespace std;

int main()
{

    Rectangle r1, r2(5, 5, 5);

    r1.setLength(5.0);
    r1.setWidth(10.0);
    r1.setHeight(10.0);

    cout << "Rectangle No.1" << endl;
    r1.showRectangle();

    cout << "Rectangle No.2" << endl;
    r2.showRectangle();

    return 0;
}