/*
This program demonstrate pass by reference.
*/

#include <iostream>

void twice(int &);
void minAndMax(int, int, int &, int &);
void swap(int &, int &);
void sort3(int &first, int &second, int &third);

using namespace std;

int main()
{

    int num, x, y, min, max;
    int a, b, c; // for sorting
    cout << "Enter a num1 and num2 ";
    cin >> x >> y;

    minAndMax(x, y, min, max);
    cout << "Max number is " << max << endl;
    cout << "Min number is " << min << endl;

    cout << "Swaping min and max" << endl;
    swap(min, max);
    cout << "After swapping: " << endl;
    cout << "Max number is " << max << endl;
    cout << "Min number is " << min << endl;

    cout << "Enter three random numbers: ";
    cin >> a >> b >> c;

    cout << "a: " << a << "\nb: " << b << "\nc: " << c << endl;
    sort3(a, b, c);
    cout << "a: " << a << "\nb: " << b << "\nc: " << c << endl;

    return 0;
}

void twice(int &x)
{
    x *= 2;
}

void minAndMax(int num1, int num2, int &min, int &max)
{
    if (num1 > num2)
    {
        max = num1;
        min = num2;
    }
    else
    {
        max = num2;
        min = num1;
    }
}

void swap(int &x, int &y)
{
    int z;
    z = y;
    y = x;
    x = z;
}

void sort3(int &first, int &second, int &third)
{
    if (first > second)
    {
        swap(first, second);
        if (second > third)
        {
            swap(second, third);
        }
    }
    if (second > third)
    {
        swap(second, third);
    }
    if (first > second)
    {
        swap(first, second);
    }
}