/*
Consider the following prototype:
void foo (const int * p);
What restrictions does the const keyword provide within the implementation of foo?

The function cannot modify the integet value pointed to by p.
However, the pointer p itself can be changed to point somewhere else.
*/
#include <iostream>

void foo(const int *p)
{
    std::cout << *p << std::endl; // reading is fine
    // *p = 20;                   // cannot modify the value through p
    p = nullptr; // the address(the value of the pointer itself) can change because p is not a const pointer).
}