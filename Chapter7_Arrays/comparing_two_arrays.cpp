/*
This program compare two arrays of same data type.
Note: When you use the == operator with array names, the operator compares the
beginning memory address of the arrays, not the contents of the arrays.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 5;
    int array1[SIZE] = {1, 2, 3, 4, 5};
    int array2[SIZE] = {1, 2, 3, 4, 5};

    bool isEqual = true;
    int count = 0;

    while (isEqual && count < SIZE)
    {
        if (array1[count] == array2[count])
        {
            count++;
        }
        else
        {
            isEqual = false;
        }
    }

    isEqual ? cout << "This two arrays are equal." << endl : cout << "This two arrays are not equal." << endl;

    return 0;
}