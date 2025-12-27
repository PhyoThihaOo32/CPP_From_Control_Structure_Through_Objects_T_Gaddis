/*
This program dynamically allocates an array to hold test scores.
It:
  - Prompts the user for the number of tests
  - Accepts test scores and stores them dynamically
  - Sorts the scores in ascending order (using bubble sort)
  - Calculates and displays the average score
  - Drops the lowest score and recalculates the adjusted average
  - Displays the sorted list with appropriate formatting

All array operations use pointer notation.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double *createTestScoreArray(int);
void deleteArray(double *);
void bubbleSort(double *, int);
double calcAverage(const double *, int);
double calcAverageDropLowest(double *, int);
void display(const double *, int);
int findLowestScore(double *, int);

int main()
{
    double *scores = nullptr;
    int numTests;

    cout << "Enter number of test scores: ";
    cin >> numTests;

    // Input validation
    while (numTests <= 1) // must have at least 2 to drop one
    {
        cout << "Number of tests must be greater than 1. Try again: ";
        cin >> numTests;
    }

    // Create and populate array
    scores = createTestScoreArray(numTests);

    // Sort the array in ascending order
    bubbleSort(scores, numTests);

    // Display sorted list
    cout << "\n------------------------------------\n";
    cout << " Sorted Test Scores\n";
    cout << "------------------------------------\n";
    display(scores, numTests);

    // Calculate average including all scores
    double avg = calcAverage(scores, numTests);
    cout << "\nAverage Score (All): " << fixed << setprecision(2) << avg << endl;

    // Calculate average dropping the lowest score
    double adjustedAvg = calcAverageDropLowest(scores, numTests);
    cout << "Average Score (Lowest Dropped): " << fixed << setprecision(2) << adjustedAvg << endl;

    // Free memory
    deleteArray(scores);
    scores = nullptr;

    return 0;
}

// Dynamically allocate memory and get user input
double *createTestScoreArray(int n)
{
    double *ptr = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter score #" << i + 1 << ": ";
        cin >> *(ptr + i);

        while (*(ptr + i) < 0)
        {
            cout << "Score cannot be negative. Enter again: ";
            cin >> *(ptr + i);
        }
    }

    return ptr;
}

// Bubble sort using pointer notation
void bubbleSort(double *arr, int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (*(arr + i) > *(arr + i + 1))
            {
                double temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

// Calculate average using pointer notation
double calcAverage(const double *arr, int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
        total += *(arr + i);

    return total / size;
}

// Calculate average after dropping the lowest score
double calcAverageDropLowest(double *arr, int size)
{
    int lowestIndex = findLowestScore(arr, size);
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != lowestIndex)
            total += *(arr + i);
    }

    return total / (size - 1);
}

// Display array contents using pointer notation
void display(const double *arr, int size)
{
    cout << left << setw(10) << "Index" << setw(10) << "Score" << endl;
    cout << "----------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(10) << (i + 1)
             << setw(10) << *(arr + i) << endl;
    }
}

// Deallocate memory
void deleteArray(double *ptr)
{
    delete[] ptr;
}

// Find the index of the lowest test score
int findLowestScore(double *array, int size)
{
    int lowestIndex = 0;
    double lowest = *(array + 0);

    for (int i = 1; i < size; i++)
    {
        if (*(array + i) < lowest)
        {
            lowest = *(array + i);
            lowestIndex = i;
        }
    }

    return lowestIndex;
}