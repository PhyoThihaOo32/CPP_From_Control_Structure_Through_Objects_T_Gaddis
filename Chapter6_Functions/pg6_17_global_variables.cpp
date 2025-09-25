/*
Global variable is any variables defined outside all the functions in a program.
The scope of global variable is the portion of the program from the variable definition to the end.
This program demonstrate the use of global variables.
*/

#include <iostream>

using namespace std;

// function prototype
void show_studentAge();

// declare global variable and initialized to 20
// unless explicitly defined, global variale are automatically initialized to 0, for character is NULL
int age = 20;

int main()
{

    cout << "Age: " << age << endl;
    show_studentAge();
    cout << "Age: " << age << endl;
}

void show_studentAge()
{
    cout << "Age: " << age << endl;
    age = 25;
}