/*
This program demonstrates the STL algorithm for_each().
It applies a user-defined function to each element in a vector.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for for_each
using namespace std;

// Function that doubles a number (passed by reference)
void doubleValue(int &value)
{
    value *= 2;
}

int main()
{
    vector<int> vect;
    vector<int>::iterator iter;

    // Fill vector with numbers 0–9
    for (int i = 0; i < 10; i++)
        vect.push_back(i);

    cout << "Original vector elements:\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // Apply doubleValue() to every element in the vector
    for_each(vect.begin(), vect.end(), doubleValue);

    cout << "\nVector elements after doubling:\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}