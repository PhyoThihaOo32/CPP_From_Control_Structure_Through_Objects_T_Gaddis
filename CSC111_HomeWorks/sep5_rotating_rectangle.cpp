/*
This program roatate the rectangle and calculate the new area
*/

#include <iostream>

int main()
{

    double length, width, area, temp;
    length = 5.5;
    width = 6.75;
    area = length * width;

    // Printing Initital value of length, width and area
    std::cout << "-----Before 90 Degree Rotation-----" << std::endl;
    std::cout << "Length:\t" << length << "\n"
              << "Width:\t" << width << "\n"
              << "Area:\t" << area << std::endl;

    // Rotate 90 Degree
    temp = length;
    length = width;
    width = temp;
    area = length * area;

    // Printing Result after rotation
    std::cout << "-----After 90 Degree Rotation-----" << std::endl;
    std::cout << "Length:\t" << length << "\n"
              << "Width:\t" << width << "\n"
              << "Area:\t" << area << std::endl;

    return 0;
}