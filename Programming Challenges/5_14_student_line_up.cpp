/*
This program prompts the user to enter the number of students in the class,
then loops to read that many names.
Once all the names have been read, it reports which student would be at the
front of the line and which one would be at the end of the line alphabetically.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num_students;
    string name, first_student, last_student;
    bool firstInput = true;

    cout << "Enter the number of students: ";
    cin >> num_students;

    // Input validation
    while (num_students <= 0)
    {
        cout << "Invalid input. Number of students must be greater than 0: ";
        cin >> num_students;
    }

    for (int i = 1; i <= num_students; i++)
    {
        cout << "Enter the first name of student " << i << ": ";
        cin >> name;

        if (firstInput)
        {
            first_student = last_student = name;
            firstInput = false;
        }
        else
        {
            if (name < first_student)
                first_student = name;
            if (name > last_student)
                last_student = name;
        }
    }

    cout << "\n-----------------------------------\n";
    cout << "First student (front of the line): " << first_student << endl;
    cout << "Last student (end of the line):   " << last_student << endl;
    cout << "-----------------------------------\n";

    return 0;
}