#include <iostream>

using namespace std;

int binarySearch(int[], int, int);

int main()
{

    const int SIZE = 10;
    int arr[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int user_input, index;

    cout << "Enter the search value: ";
    cin >> user_input;

    index = binarySearch(arr, user_input, SIZE);

    if (index != -1)
    {
        cout << "The search value is at index " << index << " of value: " << arr[index] << endl;
    }
    else
    {
        cout << "The value cannot be found." << endl;
    }

    return 0;
}

int binarySearch(int sorted_array[], int search_value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    bool found = false;
    int position = -1;
    while (found == false && first <= last)
    {
        middle = (first + last) / 2; // middle inside the loop because middle will changed for every iteration
        if (sorted_array[middle] == search_value)
        {
            found = true;
            position = middle;
        }
        else if (sorted_array[middle] > search_value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}