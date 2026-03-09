/*
reinterpret_cast (C++ Type Casting)

reinterpret_cast is a C++ type cast used to convert one pointer type
or reference type into another completely different type.

It does NOT change the actual data in memory. It only tells the compiler
to treat the existing memory as if it were another type.

This cast is usually used in low-level programming such as:
- binary file input/output
- memory manipulation
- hardware or system-level programming

Example:
int value = 65;
char* ptr = reinterpret_cast<char*>(&value);

Here, the memory address of an integer is treated as a char pointer.

Important:
reinterpret_cast is powerful but unsafe if used incorrectly,
because it can break type safety and lead to undefined behavior.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    const int SIZE = 10;
    int num[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num2[SIZE];

    fstream file;
    file.open("binaryII.dat", ios::out | ios::binary);

    file.write(reinterpret_cast<char *>(num), sizeof(num));

    file.close();

    file.open("binaryII.dat", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(num2), sizeof(num2));

    for (int i = 0; i < SIZE; i++)
    {
        cout << num2[i] << " ";
    }
    file.close();

    return 0;
}