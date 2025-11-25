/*
This program displays all of the numbers in the array that are greater than the number n.
It dynamically generates an array with random integers and shows only those greater than a user-specified threshold.
*/

#include <iostream>
#include <cstdlib>
#include <ctime> // for time(0)
using namespace std;

// Function prototypes
int *getRandomNumArray(int);
void largerThanN(int[], int, int);

int main()
{
    int size, n;

    cout << "How many numbers do you want to generate? ";
    cin >> size;

    int *ptr = getRandomNumArray(size);

    cout << "\nGenerated numbers:\n";
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }

    cout << "\n\nEnter a number — display all numbers greater than it: ";
    cin >> n;

    cout << "\n-----------------------------\n";
    cout << "Numbers greater than " << n << ": ";
    largerThanN(ptr, size, n);
    cout << endl;

    delete[] ptr; // Free dynamically allocated memory
    ptr = nullptr;

    return 0;
}

// Displays numbers greater than n
void largerThanN(int array[], int size, int n)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > n)
        {
            cout << array[i] << " ";
            found = true;
        }
    }
    if (!found)
        cout << "None";
}

// Returns a dynamically allocated array with random numbers
int *getRandomNumArray(int num)
{
    if (num <= 0)
        return nullptr;

    int *ptr = new int[num];
    srand(time(0));

    for (int i = 0; i < num; i++)
    {
        ptr[i] = rand() % 100; // random number between 0–99
    }

    return ptr;
}