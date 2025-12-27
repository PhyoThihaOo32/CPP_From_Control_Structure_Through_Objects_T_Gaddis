#include <iostream>

using namespace std;

int doSomething(int &, int &);
int doSomething(int *, int *);

int main()
{
    int x = 2, y = 4;

    cout << doSomething(x, y) << endl;

    x = 2, y = 4;
    cout << doSomething(&x, &y) << endl;

    return 0;
}

int doSomething(int &x, int &y)
{
    int temp = x;
    x = y * 10;
    y = temp * 10;

    return x + y;
}

int doSomething(int *xptr, int *yptr)
{
    int temp = *xptr;
    *xptr = *yptr * 10;
    *yptr = temp * 10;
    return (*xptr) + (*yptr);
}