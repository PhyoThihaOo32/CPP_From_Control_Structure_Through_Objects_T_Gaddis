#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    const int SIZE = 10;

    // Create SimpleVector objects for int and double types
    SimpleVector<int> intTable(SIZE);
    SimpleVector<double> doubleTable(SIZE);

    // 🔹 Store values in both vectors
    for (int i = 0; i < SIZE; i++)
    {
        intTable[i] = i * 2;
        doubleTable[i] = i * 2.14;
    }

    // 🔹 Display original values
    cout << "IntTable Elements: ";
    for (int i = 0; i < SIZE; i++)
        cout << intTable[i] << " ";
    cout << endl;

    cout << "DoubleTable Elements: ";
    for (int i = 0; i < SIZE; i++)
        cout << doubleTable[i] << " ";
    cout << endl;

    // 🔹 Add 5 to each element
    cout << "\nAdding 5 to each element..." << endl;
    for (int i = 0; i < SIZE; i++)
    {
        intTable[i] += 5;
        doubleTable[i] += 5;
    }

    cout << "Updated IntTable: ";
    for (int i = 0; i < SIZE; i++)
        cout << intTable[i] << " ";
    cout << endl;

    cout << "Updated DoubleTable: ";
    for (int i = 0; i < SIZE; i++)
        cout << doubleTable[i] << " ";
    cout << endl;

    // 🔹 Increment each element by 1
    cout << "\nIncrementing all elements by 1..." << endl;
    for (int i = 0; i < SIZE; i++)
    {
        intTable[i]++;
        doubleTable[i]++;
    }

    // 🔹 Final output
    cout << "Final IntTable: ";
    for (int i = 0; i < SIZE; i++)
        cout << intTable[i] << " ";
    cout << endl;

    cout << "Final DoubleTable: ";
    for (int i = 0; i < SIZE; i++)
        cout << doubleTable[i] << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------------
💡 Summary:
This program demonstrates a class template (`SimpleVector`)
that mimics a simplified version of C++’s `std::vector`.

Key Concepts:
- Template programming: works with multiple data types (int, double, etc.)
- Operator overloading (`[]`): allows array-style access
- Exception handling (bad_alloc, subError)
- Dynamic memory management (allocation and cleanup in constructors/destructor)
- Returning by reference allows direct modification of stored elements

The program shows that templates make it possible to reuse one class
for different data types while maintaining type safety.
-----------------------------------------------
*/