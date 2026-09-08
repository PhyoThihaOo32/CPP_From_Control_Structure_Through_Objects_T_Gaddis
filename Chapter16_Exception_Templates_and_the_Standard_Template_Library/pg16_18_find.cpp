/*
This program demonstrates the use of the STL algorithm find().
The find() function searches for a specific value in a container
and returns an iterator to the first occurrence of that value.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for find()
using namespace std;

int main()
{
    vector<int> vect;
    vector<int>::iterator iter;

    // Fill the vector with values 0–9
    for (int i = 0; i < 10; i++)
        vect.push_back(i);

    // Display all elements
    cout << "Vector elements:\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // Use find() to locate the value 9
    iter = find(vect.begin(), vect.end(), 9);

    if (iter != vect.end())
        cout << "Value 9 found at position: " << (iter - vect.begin()) << endl;
    else
        cout << "Value 9 not found." << endl;

    return 0;
}