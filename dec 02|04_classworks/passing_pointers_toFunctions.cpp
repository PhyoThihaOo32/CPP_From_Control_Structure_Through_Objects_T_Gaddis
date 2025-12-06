#include <iostream>

using namespace std;

void minMax(int, int, int, int *, int *);
void tripleIt(int *);
void swap_by_ptr(char *, char *);

int main()
{

    int big;
    int small;

    int penalty = 9;
    char a = 'A', b = 'b';

    minMax(1, 4, 5, &big, &small);

    cout << big << " " << small << " " << endl;

    tripleIt(&penalty);
    cout << "Tripled penalty : " << penalty << endl;

    cout << "Before swapping: " << endl;
    cout << a << " " << b << endl;
    swap_by_ptr(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}

void minMax(int a, int b, int c, int *big, int *small)
{
    if (a > b && a > c)
        *big = a;
    else if (b > a && b > c)
        *big = b;
    else
        *big = c;

    if (a < b && a < c)
        *small = a;
    else if (b < a && b < c)
        *small = b;
    else
        *small = c;
}

// tipleIt is a function that takes one argument nad returns no value.
// the argument is a pointer to int
// the function triple the value the argument point to and stores it back

void tripleIt(int *ptr)
{
    *ptr *= 3; // *ptr = *ptr * 3;
}

void swap_by_ptr(char *cp1, char *cp2)
{
    char temp;
    temp = *cp2;
    *cp2 = *cp1;
    *cp1 = temp;
}
