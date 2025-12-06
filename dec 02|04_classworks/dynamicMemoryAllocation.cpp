/*
Dynamic Memory Allocation
C- Melloc
*/

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int *ptr = nullptr;
    ptr = new int; // dynamically allocated memory - int

    *ptr = 25;

    cout << *ptr << endl;

    delete ptr; // not really delecting the pointer - delecting the memory the pointer point to
    ptr = nullptr;

    return 0;
}
