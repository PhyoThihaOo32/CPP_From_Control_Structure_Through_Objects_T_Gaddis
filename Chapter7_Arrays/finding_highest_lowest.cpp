/*
The algorithms for finding the highet and lowest values in an array.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 50;
    int rand_num[SIZE] = {
        12, 45, 78, 23, 56, 89, 34, 67, 90, 11,
        42, 63, 74, 55, 81, 29, 10, 38, 95, 47,
        50, 72, 14, 26, 60, 35, 88, 77, 22, 18,
        64, 31, 99, 5, 83, 17, 53, 70, 41, 97,
        8, 46, 66, 19, 25, 39, 84, 58, 93, 61};

    int highest = rand_num[0];
    int lowest = rand_num[0];

    // finding the highest number in the array
    for (int i = 1; i < SIZE; i++)
    {
        if (rand_num[i] > highest)
        {
            highest = rand_num[i];
        }
    }

    cout << "Highest number in the array: " << highest << endl;

    // finding the lowest number in the array
    for (int i = 1; i < SIZE; i++)
    {
        if (rand_num[i] < lowest)
        {
            lowest = rand_num[i];
        }
    }

    cout << "Lowest number int the array: " << lowest << endl;
}