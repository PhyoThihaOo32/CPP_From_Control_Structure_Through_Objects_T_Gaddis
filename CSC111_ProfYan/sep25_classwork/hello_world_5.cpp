/*
This program demonstrate the use of loops [ for loop, while loop, do while loop ].
*/

#include <iostream>

using namespace std;

int main()
{
    int i;

    // print "Hello World" 5 times
    cout << " print Hello World 5 times" << endl;
    for (i = 1; i <= 5; i++)
    {
        cout << "Hello World" << endl;
    }

    // print integers 1 - 5 seperated by space
    cout << "print integers 1 - 5 seperated by space" << endl;
    for (i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }

    // print integers 0 - 10 seperated by space
    cout << "\nprint integers 0 - 10 seperated by space" << endl;
    for (i = 0; i <= 10; i++)
    {
        cout << i << " ";
    }

    // print integers 10 to 0 seperated by space
    cout << "\nprint integers 10 to 0 seperated by space" << endl;
    for (i = 10; i >= 0; i--)
    {
        cout << i << " ";
    }


    return 0;
}