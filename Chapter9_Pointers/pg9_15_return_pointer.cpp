/*
Function can return pointers, but make sure pointer references still exists.
Should return a pointer from a function only if it is
- a pointer to an item that was passed into the function as an argument
- a pointer to a dynamically allocated chunk of memory
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *getRandomNumber(int);

int main()
{

    int *ptr_ranNum = getRandomNumber(10);

    // display the numbers
    for (int i = 0; i < 10; i++)
    {
        cout << *(ptr_ranNum + i) << endl;
    }

    delete[] ptr_ranNum;

    ptr_ranNum = nullptr;

    return 0;
}

int *getRandomNumber(int num)
{
    int *ptr_iArray = nullptr; // pointer to int

    if (num <= 0)
        return nullptr;

    ptr_iArray = new int[num]; // dyn allocated int array with num size

    srand(time(0));

    for (int i = 0; i < num; i++)
    {
        ptr_iArray[i] = rand() % 100;
    }

    return ptr_iArray;
}