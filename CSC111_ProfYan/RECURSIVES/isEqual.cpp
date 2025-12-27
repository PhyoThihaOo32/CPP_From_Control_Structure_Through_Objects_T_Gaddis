#include <iostream>

using namespace std;

bool isEqual(int, int);
int sum(int);
int power(int, int);

int main()
{

    if (isEqual(3, 4))
    {
        cout << "Not Equal Numbers" << endl;
    }
    else
    {
        cout << "Equal Numbers." << endl;
    }

    cout << sum(5) << endl;

    cout << power(5, 3) << endl;

    return 0;
}

/*
The function compares x and y recursively without using == directly for non-zero numbers.
    •	It reduces both numbers by 1 until they reach zero.
    •	If both hit zero at the same time → they’re equal → return true.
    •	If one reaches zero first → not equal → return false.
*/

bool isEqual(int x, int y)
{
    if (x == 0 && y == 0)
        return true;
    else if (x == 0 || y == 0)
        return false;
    else
        isEqual(x - 1, y - 1);
}

/*
This function named sum() takes a single integer parameter n
and recursively calculates the sum of all integers from 1 to n.

Base Case:
 - If n equals 1, the function returns 1.

Recursive Case:
 - Otherwise, it returns n plus the sum of all integers from 1 to (n - 1).

For example:
 sum(5) = 5 + 4 + 3 + 2 + 1 = 15
*/
int sum(int n)
{

    if (n <= 0)
        return 0;
    else
        return n + sum(n - 1);
}

/*
This function named power() takes two integer parameters, x and n,
and recursively calculates and returns the value of x raised to the nth power.

Base Case:
 - If n equals 0, the function returns 1 (since any number to the 0th power is 1).

Recursive Case:
 - Otherwise, it returns x multiplied by power(x, n - 1).

For example:
 power(2, 3) = 2 * 2 * 2 = 8
 power(5, 0) = 1
*/

int power(int x, int y)
{
    if (y <= 0)
        return 1;
    return x * power(x, y - 1);
}