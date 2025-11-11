#include <iostream>

using namespace std;

int factorial(int n);
int summation(int);

int main()
{

    cout << factorial(5) << endl;
    cout << summation(10) << endl;
    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int summation(int n)
{
    if (n == 1) // base case
        return 1;
    else
        return n + summation(n - 1);
}