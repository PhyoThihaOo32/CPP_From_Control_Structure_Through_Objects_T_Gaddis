#include <iostream>

using namespace std;

// recursive algorithm to find greatest common divisor
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

int main()
{

    cout << gcd(24, 12);

    /*
    gcd(12, 30) <- 6
    gcd(30 % 12, 24) -> gcd (6, 12) <- 6
    gcd(12 % 6, 6) -> gcd(0, 6) -> 6
    */

    return 0;
}