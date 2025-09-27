/*
Local Variables are destroyed when the function terminate and re-created when the function starts again.
*/

#include <iostream>

using namespace std;

// function prototype
void showNumberZero();

int main()
{
    showNumberZero();
    showNumberZero();

    return 0;
}

// this function show number
void showNumberZero()
{
    int number = 0;

    cout << "Number = " << number << endl;
    number = 12;
    
}
