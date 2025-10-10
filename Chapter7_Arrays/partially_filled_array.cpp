/*
This program demostrate the use of partially filled array.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 100;
    int num[SIZE];
    int user_number;

    int count = 0; // to count the number of elements in the array

    // ask user to enter the integers in the array
    cout << "Enter the number or -1 to quit.";
    cin >> user_number;

    while (user_number != -1 && count < SIZE)
    {
        num[count] = user_number;
        count++;

        cout << "Enter the number or -1 to quit.";
        cin >> user_number;
    }

    for (int i = 0; i < count; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}