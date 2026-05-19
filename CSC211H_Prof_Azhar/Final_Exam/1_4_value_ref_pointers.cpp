/*
Passing Pointer by Value and By Reference

- when we passed pointer by value into a function we can change the value of the pointer pointing to
  but not the original address of the pointer
- when passing pointer by reference, we can do both
*/

#include <iostream>

using namespace std;

void changeValue(int *ptr)
{
    *ptr = 25;
    // ptr = new int; // only changes local copy of the pointer - have no effect to original pointer
}
void changeValueAndAddress(int *&ptr)
{
    delete ptr;
    ptr = new int(89);
}

int main()
{
    int num = 20;
    int *ptr = &num;
    changeValue(ptr);
    cout << "num is now: " << num << endl;

    // pass pointer by reference
    int *rPtr = new int(10);
    cout << "rPtr before: " << *rPtr << endl;

    changeValueAndAddress(rPtr);
    cout << "rPtr after: " << *rPtr << endl;

    delete rPtr; // clean up allocated memory

    return 0;
}