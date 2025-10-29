/*
Pseudocode for a function that perform the linear search:
    Set found to false
    Set position to -1 [ -1 is not a valid subscript]
    Set index to 0
    while found is false and index < number of elements
        if list[index] is equal to search value
            found = true
            position = index
        End if
        Add 1 to index
    End while
    return position
*/

#include <iostream>

using namespace std;

int searchList(int[], int, int);

int main()
{

    const int SIZE = 100;
    int test1[SIZE] = {
        29, 49, 12, 98, 100, 78, 62, 15, 92, 19,
        56, 87, 33, 45, 61, 27, 90, 73, 8, 66,
        3, 84, 39, 58, 20, 99, 42, 16, 94, 7,
        28, 53, 10, 81, 24, 68, 12, 93, 35, 50,
        71, 5, 97, 23, 88, 64, 17, 48, 59, 9,
        25, 72, 40, 11, 30, 63, 91, 36, 85, 2,
        14, 60, 77, 1, 83, 31, 54, 76, 13, 65,
        26, 80, 43, 21, 67, 34, 70, 38, 55, 18,
        75, 6, 82, 22, 57, 46, 41, 79, 4, 95,
        47, 32, 52, 86, 44, 74, 37, 96, 89, 51};
    int search_num,
        result;

    // ask user the number of serach
    cout << "Enter the number that you are looking for: ";
    cin >> search_num;

    // find the value and store the result
    result = searchList(test1, SIZE, search_num);

    // display the result and index if found
    if (result == -1)
    {
        cout << "The number that you are looking for is not in the array." << endl;
    }
    else
    {
        cout << "The number that you are looking for is at index " << result << endl;
    }

        return 0;
}

int searchList(int list[], int array_size, int searchValue)
{
    int position = -1;
    int index = 0;
    bool found = false;

    while (index < array_size && !found)
    {
        if (list[index] == searchValue)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}