/*
This program demonstrat the vector pop_back member function.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> values;

    // stores values in the vector
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    cout << "The size of the value is " << values.size() << endl;

    // remove values from the vector
    values.pop_back();
    cout << "The size of the value is now " << values.size() << endl;
    values.pop_back();
    cout << "The size of the value is now " << values.size() << endl;
    values.pop_back();
    cout << "The size of the value is now " << values.size() << endl;

    return 0;
}