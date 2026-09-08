/*
This program demonstrates use of STL algorithms:
1. random_shuffle() → randomly rearranges elements.
2. sort() → sorts elements in ascending order.
3. binary_search() → efficiently searches a sorted container.
*/

/*
Note:
- random_shuffle() is deprecated in C++14 and removed in C++17.
- Use std::shuffle() instead with a random engine from <random>.
- shuffle(begin, end, engine) provides better randomness and safety.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for random_shuffle, sort, binary_search
using namespace std;

int main()
{
    vector<int> vect;

    // Fill vector with values 0–9
    for (int count = 0; count < 10; count++)
        vect.push_back(count);

    cout << "vect has " << vect.size() << " elements.\n";

    // Display initial contents
    cout << "Initial vector contents:\n";
    for (int val : vect)
        cout << val << " ";
    cout << endl;

    // Randomly shuffle the vector’s contents
    random_shuffle(vect.begin(), vect.end());

    cout << "\nVector elements after random_shuffle:\n";
    for (int val : vect)
        cout << val << " ";
    cout << endl;

    // Sort the vector’s elements (binary_search requires sorted data)
    sort(vect.begin(), vect.end());

    cout << "\nVector after sort:\n";
    for (int val : vect)
        cout << val << " ";
    cout << endl;

    // Perform binary search for element '7'
    cout << "\nSearching for 7...\n";
    if (binary_search(vect.begin(), vect.end(), 7))
        cout << "7 is in the vector.\n";
    else
        cout << "7 was not found.\n";

    return 0;
}