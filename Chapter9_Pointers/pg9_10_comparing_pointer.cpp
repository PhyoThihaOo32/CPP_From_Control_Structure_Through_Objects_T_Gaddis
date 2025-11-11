/*
If one address comes before another address in memeory, the first address is considered "less than" the second.
Pointers may be compared by using relational operators ( > < == != >= <=)
*/

#include <iostream>

using namespace std;

int main()
{

    int numbers[5] = {10, 20, 30, 40, 50};

    int *ptr = numbers;

    // display the numbers in the array - in ascending order
    while (ptr <= &numbers[4])
    {
        cout << *ptr++ << " ";
    }

    cout << "\nThe capability of comparing address gives you another way to be sure"
         << "\na pointer does not go beyond the boundaries of an array." << endl;

    // display the numbers in the array - in descending order
    // ptr is now pointing to the end of the array element
    while (--ptr >= numbers)
    {
        cout << *ptr << " ";
    }

    return 0;
}