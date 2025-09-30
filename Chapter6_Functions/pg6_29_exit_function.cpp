/*
When the exit function is called, it causes the program to stop, regardless of which function contains the call.
To use the exit function, you must include the cstdlib header.
exit function takes an integer argument.
-if not sure use: EXIT_FAILURE: unsuccessful exit / EXIT_SUCCESS: successful exit
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void exitFunction();

int main()
{
    exitFunction();
    cout << "Hello World" << endl;
    return 0;
}

void exitFunction()
{
    cout << "Bye!" << endl;
    exit(0);
}