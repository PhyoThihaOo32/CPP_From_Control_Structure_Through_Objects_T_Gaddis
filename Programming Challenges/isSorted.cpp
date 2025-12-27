#include <iostream>

using namespace std;

bool isSorted(int[], int, bool);

int main()
{

    return 0;
}

bool isSorted(int array[], int size, bool asc)
{
    if (asc)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i + 1] < array[i])
            {
                return true;
            }
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i + 1] > array[i])
            {
                return true;
            }
        }
    }
    return false;
}