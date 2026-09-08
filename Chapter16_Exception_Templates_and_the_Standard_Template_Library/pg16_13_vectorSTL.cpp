/*
This program demonstates the vector STL.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int count;

    vector<int> vect;

    // use the size member to get the number of elements in the vector
    cout << "vect starts with " << vect.size() << " elements." << endl;

    // use push_back to add values into the vector from the end
    for (count = 0; count < 10; count++)
    {
        vect.push_back(count);
    }

    // display the size of vector
    cout << "Now vect has " << vect.size() << " elements." << endl;

    // display the elements using [] operator
    for (count = 0; count < vect.size(); count++)
    {
        cout << vect[count] << " ";
    }

    cout << endl;

    // use pop_back function to remove the elements
    for (count = 0; count < 10 /*vect.size()*/; count++)
    /*
    You are modifying (pop_back) the vector while using its size() inside the same loop condition.
    As pop_back() removes elements, vect.size() keeps decreasing —
    but your count keeps increasing, which means the loop will not behave as expected.
    */
    {
        vect.pop_back();
    }

    // display the size of vector
    cout << "Now vect has " << vect.size() << " elements." << endl;

    return 0;
}