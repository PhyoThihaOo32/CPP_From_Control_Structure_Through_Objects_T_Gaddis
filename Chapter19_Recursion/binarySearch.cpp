#include <iostream>

using namespace std;

int binarySearch(int arr[], int i, int j, int x)
{
    if (i > j)
        return -1;

    int mid = (i + j) / 2;

    if (x == arr[mid])
        return arr[mid];
    else if (x > arr[mid])
        return binarySearch(arr, mid + 1, j, x);
    else
        return binarySearch(arr, i, mid - 1, x);
}

int main()
{

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binarySearch(arr, 0, 9, 2);

    /*

    binarySearch(arr,0,9,2) <== 2
    mid = 4
    arr[4] = 4 != 2 -> 2 < arr[mid]
    binarySearch(arr, 0, 3, 2) -> {0,1,2,3} <== 2
    mid = (0+ 3)/2 = 1
    arr[1] = 1 != 2
    2 > 1
    binarySearch(arr,2,3,2) -> {2,3} <== 2
    mid = 0
    arr[mid] = 2 -> return 2

    */

    return 0;
}