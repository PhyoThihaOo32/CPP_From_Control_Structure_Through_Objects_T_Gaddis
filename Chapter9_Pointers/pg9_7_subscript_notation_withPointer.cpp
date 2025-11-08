/*
Not only is pointer notation is used with the array name, but also subscript notation is used with the pointer.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const int NUM_COIN = 5;
    double coins[NUM_COIN] = {0.01, 0.05, 0.10, 0.25, 0.50};

    double *ptr_coin; // pointer to store double
    ptr_coin = coins;

    cout << "using subscripts with the pointer" << endl;
    // diplay the contents of the coin array - using subscripts with the pointer
    for (int i = 0; i < NUM_COIN; i++)
    {
        cout << ptr_coin[i] << " ";
    }
    cout << "\npointer notation with array name" << endl;

    // pointer notation with array name
    for (int i = 0; i < NUM_COIN; i++)
    {
        cout << *(coins + i) << " ";
    }

    cout << "\npointer notation with pointer" << endl;
    // pointer notation with pointer
    for (int i = 0; i < NUM_COIN; i++)
    {
        cout << *(ptr_coin + i) << " ";
    }

    return 0;
}