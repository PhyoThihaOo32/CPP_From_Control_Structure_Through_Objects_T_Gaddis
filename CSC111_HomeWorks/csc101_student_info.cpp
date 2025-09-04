/*
This program will print a brief summary of student info from the previous CSC101 course.
This program will also print a paragraph about the student's current feelings about programming and what he/she is looking forward to learning
This program demonstrates the use of different data types, descriptive variable names, and escape characters and printing output
*/

#include <iostream>

using namespace std;

int main()
{
    // Declaring and Initializing variables
    string first_name = "Phyo";
    string last_name = "Oo";
    unsigned int number_of_py_programs = 101;
    double average_grade_csc101 = 99.998;
    float tuition_fees = 2382.82F;
    char fav_symbol = '*';

    // Printing student info
    cout << "\t\tStudent Info\n";
    cout << "Student Name:\t\t" << last_name << ", " << first_name << endl;
    cout << "Python Programs:\t" << number_of_py_programs << endl;
    cout << "Grade Avg:\t\t" << average_grade_csc101 << endl;
    cout << "Semester Tuition:\t$" << tuition_fees << endl;
    cout << "Fav Symbol:\t\t" << fav_symbol << endl;

    // Printing a paragraph
    cout << "\nMy name is " << first_name << " " << last_name << "."
         << "Last week, I learned about escape characters such as \\t for tab, \\n for new line, \\a for alarm (beep), and \\\" to print double quotes inside a string.\n"
         << "I’ve always been curious about how programmers create software, operating systems and programming languages, and how they’re able to write such complex code.\nAnd I wanted to create one of my own.\n"
         << "I’m looking forward to learn in detail object-oriented programming (OOP) in C++, and I’d love to see real-life code examples.\n";

    return 0; // program executed successfully
}