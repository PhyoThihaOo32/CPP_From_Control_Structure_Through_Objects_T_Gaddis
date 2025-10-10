/*
This program model the summation and average of number in an array.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 10;
    int num[SIZE] = {23, 7, 15, 42, 8, 19, 34, 2, 27, 11};
    int sum_total = 0;
    float average;

    // using range based for loop to get the total of numbers in the array
    for (int num : num)
    {
        sum_total += num;
    }

    // divding the total with the total numbers
    average = sum_total / SIZE;

    return 0;
}