/*
This program demonstrate a class with a destructor.
*/

#include <iostream>
#include "ContactInfo.h"

using namespace std;

int main()
{
    // Create a ContactInfo object by passing two C-string literals
    ContactInfo person("Alice", "555-1234");

    // Display the contact’s stored info
    person.showInfo();

    // When 'person' goes out of scope, the destructor is automatically called,
    // freeing the memory that was allocated by the constructor.
    return 0;
}