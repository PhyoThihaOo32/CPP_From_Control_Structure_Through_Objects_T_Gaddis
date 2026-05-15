#include <iostream>

using namespace std;

// recursive algorithm for factorial
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{

    cout << factorial(4) << endl;

    return 0;
}