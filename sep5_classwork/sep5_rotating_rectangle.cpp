/*
This program roatate the rectangle and calculate the new area
*/

#include <iostream>

int main()
{

    double length, width, area, parameter, temp;
    char answer;

    // Getting user inpnut
    std::cout << "Welcome to the Rectangle Program. \nUnits are in meter.\nOnly accept positive real numbers." << std::endl;
    std::cout << "What is the length? " << std::endl;
    std::cin >> length;

    std::cout << "What is the width? " << std::endl;
    std::cin >> width;

    area = length * width;
    parameter = 2 * (length + width);

    // Printing Initital value of length, width and area
    std::cout << "-----Before 90 Degree Rotation-----" << std::endl;
    std::cout << "Length:\t\t" << length << "\n"
              << "Width:\t\t" << width << "\n"
              << "Area:\t\t" << area << "\n"
              << "Parameter:\t" << parameter << std::endl;

    // ask user if want to rotate the rectangle
    std::cout << "Do you want to rotate the rectangle?(y/n) " << std::endl;
    std::cin >> answer;

    while (answer == 'y')
    {
        // Rotate 90 Degree
        temp = length;
        length = width;
        width = temp;
        area = length * width;
        parameter = length + width;

        // Printing Result after rotation
        std::cout << "-----After 90 Degree Rotation-----" << std::endl;
        std::cout << "Length:\t\t" << length << "\n"
                  << "Width:\t\t" << width << "\n"
                  << "Area:\t\t" << area << "\n"
                  << "Parameter:\t" << parameter << std::endl;

        // ask the user till he stopped rotating
        std::cout << "Do you want to rotate the rectangle?(y/n) " << std::endl;
        std::cin >> answer;
    }

    std::cout << "Thank you for using the program!" << std::endl;

    return 0;
}