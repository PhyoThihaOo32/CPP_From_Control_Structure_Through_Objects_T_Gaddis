/*
This program demonstrates use of STL algorithms:
min_element() and max_element().
These algorithms return iterators pointing to the smallest and largest elements in a container.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for min_element, max_element
using namespace std;

int main()
{
    vector<int> vect;
    vector<int>::iterator iter;

    // Fill vector with values 0–9
    for (int i = 0; i < 10; i++)
        vect.push_back(i);

    // Display the elements using an iterator
    cout << "Vector elements:\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    /*
    max_element(begin, end)
      → Returns an iterator to the largest element in the range.

    min_element(begin, end)
      → Returns an iterator to the smallest element in the range.
    */

    // Find the largest value
    iter = max_element(vect.begin(), vect.end());
    cout << "Largest value: " << *iter << endl;

    // Find the smallest value
    iter = min_element(vect.begin(), vect.end());
    cout << "Smallest value: " << *iter << endl;

    return 0;
}