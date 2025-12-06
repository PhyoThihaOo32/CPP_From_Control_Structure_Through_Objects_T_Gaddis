/*
This program demonstrates a class (ContactInfo) that dynamically allocates
memory for C-style strings (char arrays). It performs a deep copy to safely
store contact details and properly releases the memory in the destructor.
*/

#include <iostream>
#include <cstring> // for strlen() and strcpy()
using namespace std;

class ContactInfo
{
private:
    char *name;      // Pointer to hold the contact's name
    char *ph_number; // Pointer to hold the contact's phone number

public:
    // -------------------------------------------------------
    // Constructor: dynamically allocates memory and copies data
    // -------------------------------------------------------
    ContactInfo(const char *n, const char *p)
    {
        // Allocate memory for 'name' based on length of 'n' + 1 (for '\0')
        name = new char[strlen(n) + 1];

        // Allocate memory for 'ph_number' based on length of 'p' + 1
        ph_number = new char[strlen(p) + 1];

        // Copy each string into the newly allocated memory
        strcpy(name, n);
        strcpy(ph_number, p);

        // Now 'name' and 'ph_number' each hold their own independent copies
    }

    // -------------------------------------------------------
    // Destructor: releases dynamically allocated memory
    // -------------------------------------------------------
    ~ContactInfo()
    {
        // Always match 'new[]' with 'delete[]' to avoid memory leaks
        delete[] name;
        delete[] ph_number;

        // Optional: set to nullptr for safety
        name = nullptr;
        ph_number = nullptr;
    }

    // -------------------------------------------------------
    // Member function: displays stored contact info
    // -------------------------------------------------------
    void showInfo() const
    {
        cout << "\nContact Information\n";
        cout << "---------------------------\n";
        cout << "Name:  " << name << endl;
        cout << "Phone: " << ph_number << endl;
    }
};