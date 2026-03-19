#include <iostream>
#include <memory>

using namespace std;

int main()
{

    int max; // max size of the array

    // get the number of values to store
    cout << "How many numbers do you want to enter?" << endl;
    cin >> max;

    // define the unique_ptr smart pointer, pointing to a dynamically allocated array of ints
    unique_ptr<int[]> ptr(new int[max]);

    // get the value for the array
    for (int index = 0; index < max; index++)
    {
        cout << "Enter an integer number: ";
        cin >> ptr[index];
    }

    // display the values in the array
    cout << "Here are the values you entered: " << endl;
    for (int i = 0; i < max; i++)
    {
        cout << ptr[i] << endl;
    }

    return 0;
}
