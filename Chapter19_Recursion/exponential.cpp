#include <iostream>

using namespace std;

// recursive algorithm for computing a^n
double power(double a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}

int main()
{

    cout << power(2, 4) << endl;

    /*
    power(2,4)
    2 * power(2,3)
    2 * 2 * power(2,2)
    2 * 2 * 2 * power(2,1)
    2 * 2 * 2 * 2 * power(2,0)
    2 * 2 * 2 * 2 * 1 = 16
    */

    return 0;
}