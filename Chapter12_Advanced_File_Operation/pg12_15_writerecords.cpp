/*
This program use struct variable to store a record to a file.
Beside providing an organizational structure for data, structures also package data into a single unit.
Because structures can contain a mixture of data types, you should always use the ios::binary mode
when opening a file to store them.
*/

#include <iostream>
#include <fstream>

using namespace std;

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

// declare structure for a record
struct Info
{
    char name[NAME_SIZE];
    int age;
    char address1[ADDR_SIZE];
    char address2[ADDR_SIZE];
    char phone[PHONE_SIZE];
};

int main()
{
    Info person;
    char again;

    fstream personFile("people.dat", ios::out | ios::binary);

    do
    {
        // get data about a person
        cout << "Enter the following data about a person: " << endl;
        cout << "Name: ";
        cin.getline(person.name, NAME_SIZE);
        cout << "Age: ";
        cin >> person.age;
        cin.ignore();

        cout << "Address line1: ";
        cin.getline(person.address1, ADDR_SIZE);
        cout << "Address line2: ";
        cin.getline(person.address2, ADDR_SIZE);
        cout << "Phone: ";
        cin.getline(person.phone, PHONE_SIZE);

        // write the content of the person structure to the file
        personFile.write(reinterpret_cast<char *>(&person), sizeof(person));

        // ask user to write another record
        cout << "Do you want to enter another record?" << endl;
        cin >> again;
        cin.ignore();
    } while (again == 'Y' || again == 'y');

    // close the file
    personFile.close();

    return 0;
}

/*
Difference between getline(cin, name) and cin.getline(name, size)

1. getline(cin, name)
- This belongs to the C++ string library.
- It reads an entire line from input (including spaces).
- It stores the result in a string object.

Example:
string name;
getline(cin, name);

This is the modern and safer way to read a full line of text.

------------------------------------------------------------

2. cin.getline(name, size)
- This belongs to the C-style character array system.
- It reads a line into a character array (char[]).
- You must specify the maximum number of characters (size).

Example:
char name[50];
cin.getline(name, 50);

The function stops when:
- newline is encountered
- size-1 characters are read

------------------------------------------------------------

Key Difference

getline(cin, name)
→ works with string type

cin.getline(name, size)
→ works with char arrays

In modern C++ programs, using string with getline() is preferred.
*/