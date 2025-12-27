/*
This program demonstrate the use of array.
*/

#include <iostream>

using namespace std;

double avgTemp(double[], int);
void resetArray(double[], int);
void findMaxMin(double[], int);
void copyArray(double[], double[], int);

int main()
{

    const int DAYS = 7;

    double temperature[DAYS] = {50.5, 52.3, 48.7, 49.2, 51.0}; // initialized first 5 days
    double copy_temp[DAYS];                                    // initialize the empty array

    temperature[5] = 49.2; // assign the 6 element in the array

    // ask the user for the temperature for sunday(day 7)
    cout << "Enter the temperature for Sunday. ";
    cin >> temperature[6];

    // print out the array using range-based for loop
    for (double temp : temperature)
    {
        cout << temp << " ";
    }

    // using for loop
    for (int i = 0; i < DAYS; i++)
    {
        cout << "Temperature for day " << i + 1 << " :" << temperature[i] << endl;
    }

    cout << endl;

    // printing reverse using for loop
    for (int i = DAYS - 1; i >= 0; i--)
    {
        cout << "Temperature for day " << i + 1 << " :" << temperature[i] << endl;
    }

    // print out the memory address of the array
    cout << temperature << endl;

    // calculate the average temp and print it out
    cout << "Average temperature : " << avgTemp(temperature, DAYS) << endl;

    // print out max value from the array
    findMaxMin(temperature, DAYS);

    // copy the array
    copyArray(temperature, copy_temp, DAYS);

    // print out the copied array
    for (double temp : copy_temp)
    {
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}

double avgTemp(double array[], int size)
{
    double total = 0,
           avgTemp;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }
    avgTemp = total / size;

    return avgTemp;
}

void resetArray(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void findMaxMin(double array[], int size)
{ // 3 4 5 62 1 4
    double max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    double min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    cout << "Max value :" << max << endl;
    cout << "Min value :" << min << endl;
}

void copyArray(double array[], double array2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array2[i] = array[i];
    }
}
