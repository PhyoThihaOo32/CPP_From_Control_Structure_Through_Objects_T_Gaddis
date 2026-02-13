#include <iostream>

using namespace std;

int main()
{

    int x = 10;
    int y = 5;

    int *xptr = &x;
    int *yptr = &y;
    int *tempPtr = nullptr;

    cout << "Before: " << endl;
    cout << "xptr: " << xptr << endl;
    cout << "yptr: " << yptr << endl;
    cout << "xvalue: " << *xptr << endl;
    cout << "yvalue: " << *yptr << endl;

    tempPtr = xptr;
    xptr = yptr;
    yptr = tempPtr;

    cout << "After: " << endl;
    cout << "xptr: " << xptr << endl;
    cout << "yptr: " << yptr << endl;
    cout << "xvalue: " << *xptr << endl;
    cout << "yvalue: " << *yptr << endl;

    return 0;
}