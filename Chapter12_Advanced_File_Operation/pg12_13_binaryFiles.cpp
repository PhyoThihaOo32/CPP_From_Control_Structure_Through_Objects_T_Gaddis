/*
Binary File (Short Explanation)

A binary file stores data in raw binary form (0s and 1s) exactly as it exists in memory.
Unlike text files, binary files are not human-readable.

Binary files are commonly used for storing images, videos, compiled programs,
or structured data that needs to be saved and loaded efficiently.

In C++, binary files are opened using the ios::binary flag and data is written
or read using the write() and read() functions instead of << and >>.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    const int SIZE = 6;
    char data[SIZE] = "hello";
    char newData[SIZE];

    fstream file;
    file.open("binary.dat", ios::out | ios::binary);

    // write to the file
    file.write(data, sizeof(data));

    // close the file
    file.close();

    file.open("binary.dat", ios::in | ios::binary);

    // read from the file
    file.read(newData, sizeof(newData));

    // display the content
    for (int i = 0; i < SIZE; i++)
    {
        cout << newData[i] << " ";
    }

    file.close();

    return 0;
}