#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getRainfall(double[], int);
double calcTotal(double[], int);
double calcAverage(double[], int);
int findHighest(double[], int);
int findLowest(double[], int);

int main()
{
    const int MONTHS = 12;
    double rainfall[MONTHS];
    double total, average;
    int highMonth, lowMonth;

    cout << "This program calculates total, average, and extreme rainfall data.\n";

    // Get user input
    getRainfall(rainfall, MONTHS);

    // Compute total and average
    total = calcTotal(rainfall, MONTHS);
    average = calcAverage(rainfall, MONTHS);

    // Find highest and lowest months
    highMonth = findHighest(rainfall, MONTHS);
    lowMonth = findLowest(rainfall, MONTHS);

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n---------------- Rainfall Report ----------------\n";
    cout << "Total rainfall for the year: " << total << " inches\n";
    cout << "Average monthly rainfall:   " << average << " inches\n";
    cout << "Month " << (highMonth + 1) << " had the highest rainfall: " << rainfall[highMonth] << " inches\n";
    cout << "Month " << (lowMonth + 1) << " had the lowest rainfall:  " << rainfall[lowMonth] << " inches\n";
    cout << "-------------------------------------------------\n";

    return 0;
}

// Function to input rainfall data
void getRainfall(double rainfall[], int size)
{
    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << "Enter rainfall for month " << (i + 1) << ": ";
            cin >> rainfall[i];
            if (rainfall[i] < 0)
                cout << "Rainfall cannot be negative. Try again.\n";
        } while (rainfall[i] < 0);
    }
}

// Function to calculate total rainfall
double calcTotal(double rainfall[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
        total += rainfall[i];
    return total;
}

// Function to calculate average rainfall
double calcAverage(double rainfall[], int size)
{
    double total = calcTotal(rainfall, size);
    return total / size;
}

// Function to find the index of the highest rainfall
int findHighest(double rainfall[], int size)
{
    int highestIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (rainfall[i] > rainfall[highestIndex])
            highestIndex = i;
    }
    return highestIndex;
}

// Function to find the index of the lowest rainfall
int findLowest(double rainfall[], int size)
{
    int lowestIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (rainfall[i] < rainfall[lowestIndex])
            lowestIndex = i;
    }
    return lowestIndex;
}