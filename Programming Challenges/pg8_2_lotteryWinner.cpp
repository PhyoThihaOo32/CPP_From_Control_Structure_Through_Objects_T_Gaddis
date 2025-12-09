/*
A lottery ticket buyer purchases 10 tickets a week, always playing the same
10 five-digit "lucky" combinations.

This program lets the player enter this week's winning 5-digit number.
It performs a linear search through the list of the player's numbers and
reports whether or not one of the tickets is a winner this week.
*/

#include <iostream>
using namespace std;

// Function prototype: linear search
int linearSearchTicket(const int[], int, int);
int binarySearchTicket(const int[], int, int);
void bubbleSort(int[], int);

int main()
{
    const int SIZE = 10;
    int lotteryNum[SIZE] = {13579, 26791, 26792, 33445, 55555,
                            62483, 77777, 79422, 85647, 93121};

    int winningTicket;
    int winningIndex;

    // Ask user for this week’s winning number
    cout << "Enter this week's winning 5-digit number: ";
    cin >> winningTicket;

    // sort the array
    bubbleSort(lotteryNum, SIZE);

    // Perform binary search
    winningIndex = binarySearchTicket(lotteryNum, SIZE, winningTicket);

    // Display result
    if (winningIndex == -1)
        cout << "Sorry, you didn't win this week.\n";
    else
        cout << "Congratulations! You won with ticket #" << lotteryNum[winningIndex] << "!\n";

    return 0;
}

/*
This function performs a linear search on an integer array.
If the value is found, it returns its index; otherwise, it returns -1.
*/
int linearSearchTicket(const int array[], int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found)
    {
        if (array[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }

    return position;
}

int binarySearchTicket(const int array[], int size, int value)
{
    int first = 0,       // first index of the array
        last = size - 1, // last index of the array
        middle;
    int position = -1;  // return -1 if not found
    bool found = false; // flag set to false

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
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

void bubbleSort(int array[], int size)
{
    int temp;
    bool swap;
    do
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i + 1] < array[i])
            { // if element 0 is larger than element 1 then swap
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}