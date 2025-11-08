/*
This program demonstrate array name being dereferenced with the * operator.
*/

#include <iostream>

using namespace std;

int main()
{

    int numbers[] = {1, 2, 3, 4, 5, 6};

    cout << "Because the numbers(the array name) works like a pointer to the starting address of the array\n"
         << "the first element is retrived when numbers is dereferenced.\n";
    cout << *numbers << endl;
    cout << "When you add a value to a pointer, you are actually adding that value times\n"
         << "the size of the data type being referenced by the pointer.\n";
    cout << *(numbers + 1) << " " << *(numbers + 2) << endl;

    return 0;
}