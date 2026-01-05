#include <iostream>
#include "Cube.h"
using namespace std;

int main()
{
    double cubeLength, cubeWidth, cubeHeight;

    cout << "Enter cube length, width, and height: ";
    cin >> cubeLength >> cubeWidth >> cubeHeight;

    Cube goodCube(cubeLength, cubeWidth, cubeHeight);

    cout << "\nCube Info:\n";
    cout << "Length: " << goodCube.getLength() << endl;
    cout << "Width:  " << goodCube.getWidth() << endl;
    cout << "Height: " << goodCube.getHeight() << endl;
    cout << "Area:   " << goodCube.getArea() << endl;
    cout << "Volume: " << goodCube.getVolume() << endl;

    return 0;
}