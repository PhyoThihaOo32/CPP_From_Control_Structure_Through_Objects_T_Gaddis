/*
A lottery ticket buyer purchases 10 tickets a week, always playing the same
10 five-digit "lucky" combinations.

This program lets the player enter this week's winning 5-digit number.
It sorts the player's ticket numbers, performs a binary search,
and reports whether one of the tickets is a winner.
*/

#include <iostream>
using namespace std;

// Function prototypes
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

    // Sort the array before binary search
    bubbleSort(lotteryNum, SIZE);

    // Perform binary search
    winningIndex = binarySearchTicket(lotteryNum, SIZE, winningTicket);

    // Display result
    if (winningIndex == -1)
        cout << "Sorry, you didn't win this week.\n";
    else
        cout << "🎉 Congratulations! You won with ticket #"
             << lotteryNum[winningIndex] << "!\n";

    return 0;
}

/*
This function performs a linear search on an integer array.
If the value is found, it returns its index; otherwise, it returns -1.
*/
int linearSearchTicket(const int array[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

/*
This function performs a binary search on a sorted array.
Returns the index of the value if found, otherwise -1.
*/
int binarySearchTicket(const int array[], int size, int value)
{
    int first = 0, last = size - 1, middle;

    while (first <= last)
    {
        middle = (first + last) / 2;

        if (array[middle] == value)
            return middle;
        else if (array[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return -1;
}

/*
This function sorts an integer array using the bubble sort algorithm.
*/
void bubbleSort(int array[], int size)
{
    int temp;
    bool swapped;

    do
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++) // ✅ FIX: use size - 1 to avoid out-of-bounds
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}