/*
The series of values insides the braces and separated with commas is called an initialization list.
*/

#include <iostream>

using namespace std;

int main()
{

    const int ARRAY_SIZE = 12;
    int months_array[ARRAY_SIZE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Month " << (i + 1) << " has "
             << months_array[i] << " days" << endl;
    }

    return 0;
}