#include <iostream>

using namespace std;

// recursive algorithm for sum of elements of the array
int sumArray(int arr[], int size)
{
    if (size == 0)
        return 0;
    else
        return arr[size - 1] + sumArray(arr, size - 1);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};

    cout << sumArray(array, 5);

    /*
    array[4] + sumArray(arr,4) -> 5 + 10 = 15
    array[3] + sumArray(arr,3) -> 4 + 6 = 10
    array[2] + sumArray(arr,2) -> 3 + 3 = 6
    array[1] + sumArray(arr,1) -> 2 + 1 = 3
    array[0] + sumArray(arr,0) -> 1 + 0 = 1
    sumArray(arr,0) -> 0
    */

    return 0;
}