/*
Iterators are generalizations of pointers used to access elements in STL containers.
They allow traversal, reading, and modification of container elements without knowing the container's internal structure.

Types of iterators:
- Input iterator: Read-only, one-way traversal.
- Output iterator: Write-only, one-way traversal.
- Forward iterator: Read/write, one-way traversal.
- Bidirectional iterator: Read/write, two-way traversal.
- Random-access iterator: Read/write, two-way + can jump directly (like in vector, deque, array).
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect;

    // Define an iterator for a vector<int>
    // The compiler knows this will be a random-access iterator
    vector<int>::iterator iter;

    // Insert values into the vector
    for (int count = 0; count < 10; count++)
        vect.push_back(count * 2);

    /*
    begin() → returns an iterator pointing to the first element.
    end()   → returns an iterator pointing PAST the last element.
              (Not the last element itself!)
    */

    cout << "Forward traversal using iterator:\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " "; // *iter gives the value at iterator
    cout << endl;

    cout << "Backward traversal using iterator:\n";
    for (iter = vect.end() - 1; iter >= vect.begin(); iter--)
        cout << *iter << " ";
    cout << endl;

    return 0;
}