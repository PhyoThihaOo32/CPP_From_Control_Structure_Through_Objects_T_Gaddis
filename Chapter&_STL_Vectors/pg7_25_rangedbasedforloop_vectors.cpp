/*
This program demonstrate the range_based for loop with a vector.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // define the empty vector of int
    vector<int> numbers(5);

    // let the user enter the value into the vector
    for (int &num : numbers)
    {
        cout << "Enter the integer value: ";
        cin >> num;
    }

    // display the values
    for (int num : numbers)
    {
        cout << num << " ";
    }

    return 0;
}