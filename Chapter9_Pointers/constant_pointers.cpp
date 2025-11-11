/*
With a const pointer, it is the pointer itself that is constant. Once the pointer is initialized with an address,
it cannot point to anything else.
If a constant pointer is used as a function parameter, the parameter will be initialized with the address
that is passed as an argument into it and cannot be changed to point to anything else while the funciton is executing.
Note: We can call the function with const pointer multiple time with different arguments.
*/

#include <iostream>

using namespace std;

void setToZero(int *const);

int main()
{
    int x = 11, y = 12, z = 9;

    cout << x << " " << y << " " << z << endl;

    setToZero(&x);
    setToZero(&y);
    setToZero(&z);

    cout << x << " " << y << " " << z << endl;

    return 0;
}

void setToZero(int *const iPtr)
{
    *iPtr = 0;
}