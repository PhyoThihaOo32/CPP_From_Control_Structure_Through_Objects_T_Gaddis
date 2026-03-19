/*
This program uses a structure variable to read a record from a file.
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

    // open the file for input in binary mode.
    fstream file("people.dat", ios::in | ios::binary);

    // test for error opening the file
    if (!file)
    {
        cout << "Erro opening the file. " << endl;
        return 0;
    }

    cout << "Here are the people in the file." << endl;

    // read the first record from the file
    file.read(reinterpret_cast<char *>(&person), sizeof(person));

    // while not at the end of the file, display
    while (!file.eof())
    {
        // display the record
        cout << "Name: " << person.name << endl;
        cout << "Age: " << person.age << endl;
        cout << "Address1: " << person.address1 << endl;
        cout << "Address2: " << person.address2 << endl;
        cout << "Phone: " << person.phone << endl;

        // wait for the user to press the Enter key
        cout << "Press Enter to see next record." << endl;
        cin.get(again);

        file.read(reinterpret_cast<char *>(&person), sizeof(person));
    }

    cout << "That's all the data in the file" << endl;

        file.close();

    return 0;
}