#include <iostream>

int main()
{
    // Declaring the variables
    int number_credit;
    float student_gpa;

    // Promt and getting user informations
    std::cout << "How many credits did you take in this semester? " << std::endl;
    std::cin >> number_credit;

    std::cout << "What is your GPA from last semester? " << std::endl;
    std::cin >> student_gpa;

    // Printing out the information
    std::cout << "You took " << number_credit << " credits and your GPA is "
              << student_gpa << ".\nExcellent!" << std::endl;

    return 0;
}