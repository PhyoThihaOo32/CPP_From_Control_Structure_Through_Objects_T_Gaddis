/*
This program use a loop to display the characters for the ASCII codes 0 through 127.
And display 16 characters on each line.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const int ASCII_MIN = 0;
    const int ASCII_MAX = 127;

    for (int i = ASCII_MIN; i <= ASCII_MAX; i++)
    {
        cout << setw(3) << static_cast<char>(i);
        if (i % 16 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}