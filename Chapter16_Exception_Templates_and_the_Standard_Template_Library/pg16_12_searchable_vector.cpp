/*
This program demonstrates the SearchableVector class template.
It extends the SimpleVector template by adding a search capability
that allows finding an element's index in the vector.
*/

#include <iostream>
#include "SearchableVector.h"
using namespace std;

int main()
{
    const int SIZE = 10;
    int result;

    // Create two SearchableVector objects for int and float
    SearchableVector<int> intTable(SIZE);
    SearchableVector<float> floatTable(SIZE);

    // Store values in the vectors
    for (int i = 0; i < SIZE; i++)
    {
        intTable[i] = i * 2;
        floatTable[i] = i * 2.14f;
    }

    // Display stored values
    cout << "\nInteger Table Elements:\n";
    for (int i = 0; i < SIZE; i++)
        cout << intTable[i] << " ";
    cout << endl;

    cout << "\nFloat Table Elements:\n";
    for (int i = 0; i < SIZE; i++)
        cout << floatTable[i] << " ";
    cout << endl;

    // Search for a value in intTable
    cout << "\n🔍 Searching for 6 in intTable..." << endl;
    result = intTable.findItem(6);

    if (result == -1)
        cout << "❌ 6 was not found in intTable.\n";
    else
        cout << "✅ 6 was found at subscript " << result << ".\n";

    // Search for a value in floatTable
    cout << "\n🔍 Searching for 4.28 in floatTable..." << endl;
    result = floatTable.findItem(4.28f);

    if (result == -1)
        cout << "❌ 4.28 was not found in floatTable.\n";
    else
        cout << "✅ 4.28 was found at subscript " << result << ".\n";

    cout << "\nProgram complete.\n";
    return 0;
}

/*
Summary:
---------
This program demonstrates template inheritance and search functionality.

Key Concepts:
-------------
• SimpleVector<T> manages a dynamic array with operator[] and safe access.
• SearchableVector<T> inherits from SimpleVector<T> and adds findItem().
• Demonstrates how templates allow one class to work with multiple data types.
• The findItem() function performs a linear search and returns the index or -1.

Output Example:
---------------
Integer Table Elements:
0 2 4 6 8 10 12 14 16 18

Float Table Elements:
0 2.14 4.28 6.42 8.56 10.7 12.84 14.98 17.12 19.26

🔍 Searching for 6 in intTable...
✅ 6 was found at subscript 3.

🔍 Searching for 4.28 in floatTable...
✅ 4.28 was found at subscript 2.
*/