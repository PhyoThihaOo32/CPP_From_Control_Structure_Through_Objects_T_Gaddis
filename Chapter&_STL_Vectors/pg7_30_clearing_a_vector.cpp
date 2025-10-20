/*
This program demonstrates the vector clear member function.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> numbers(100);

    cout << "This vector has " << numbers.size() << " elements." << endl;

    numbers.clear();
    cout << "This vector has " << numbers.size() << " elements." << endl;

    return 0;
}