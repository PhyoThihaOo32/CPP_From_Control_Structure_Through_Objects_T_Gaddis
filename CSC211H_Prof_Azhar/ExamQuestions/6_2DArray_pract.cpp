/*
6)  Assume you have the following declaration (in main) :
    int  num[13] [7];
    Assume that array num is filled completely. Write functions to perform each of the following:
    a) A function that prints all elements in the array that are greater than 80 or less than 10.
    b) A function that finds the largest number in the array and returns its subscript.
    c) A function that finds and returns the average of all the numbers in the array.
    d) A function that print the entire array in a neat table, but starting with the last row and proceeding
    in reverse order to the first.
*/

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

const int ROWS = 13;
const int COLS = 7;

// function prototypes
void print(int[][COLS], int ROWS);
pair<int, int> findLargest(int[][COLS], int ROWS);
pair<int, int> find_element(int[][COLS], int, int);
double findAvg(int[][COLS], int ROWS);
void printReverse(int[][COLS], int ROWS);

int main()
{
    int array[ROWS][COLS] = {
        {12, 85, 7, 90, 34, 56, 78},
        {99, 23, 45, 67, 89, 10, 5},
        {8, 15, 22, 33, 44, 55, 66},
        {77, 88, 99, 11, 22, 33, 44},
        {55, 66, 77, 88, 99, 100, 1},
        {2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20, 21, 22},
        {23, 24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35, 36},
        {37, 38, 39, 40, 41, 42, 43},
        {44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57}};

    print(array, ROWS);
    pair<int, int> indexes = findLargest(array, ROWS);
    cout << "Largest Indes at Row: " << indexes.first
         << " and Column: " << indexes.second << endl;

    // test find max
    pair<int, int> targetIndex = find_element(array, ROWS, 26);

    if (targetIndex.first != -1 && targetIndex.second != -1)
    {
        cout << "Found Element " << 26 << " at row " << targetIndex.first
             << " and column " << targetIndex.second << endl;
    }

    // test average
    cout << "Average: " << findAvg(array, ROWS) << endl;

    // print reverse
    printReverse(array, ROWS);

    return 0;
}

// This function prints all elements in the array that are greater than 80 or less than 10.
void print(int array[][COLS], int ROWS)
{
    int cut = 0; // just to print in 5 col per row
    for (int i = 0; i < ROWS; i++)
    {

        for (int j = 0; j < COLS; j++)
        {

            if (array[i][j] > 80 || array[i][j] < 10)
            {

                cout << "|" << setw(4) << array[i][j];
                cut++;
                if (cut == 5)
                {
                    cout << "|" << endl;
                    cut = 0;
                }
            }
        }
    }
    cout << "|" << endl;
}

//  A function that finds the largest number in the array and returns its subscript.
pair<int, int> findLargest(int array[][COLS], int ROWS)
{
    int largest = array[0][0];
    int rows, cols;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] > largest)
            {
                largest = array[i][j];
                rows = i;
                cols = j;
            }
        }
    }
    return {rows, cols};
}

// This function find the target elements and return the subscript
pair<int, int> find_element(int array[][COLS], int ROWS, int target)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (target == array[i][j])
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// A function that finds and returns the average of all the numbers in the array
double findAvg(int array[][COLS], int ROWS)
{
    int sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += array[i][j];
        }
    }
    return static_cast<double>(sum) / (ROWS * COLS);
}

//  d) A function that print the entire array in a neat table,
//  but starting with the last row and proceeding
//  in reverse order to the first.
void printReverse(int array[][COLS], int ROWS)
{
    for (int i = ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << "|" << setw(3) << array[i][j];
        }
        cout << "|" << endl;
    }
}
