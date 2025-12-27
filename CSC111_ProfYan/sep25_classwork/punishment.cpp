/*
This program is for students who don't pay attention in class.
*/

#include <iostream>

using namespace std;

int main()
{

    int user_input;

    // ask user for times
    cout << "How many time you want to write it down? ";
    cin >> user_input;

    for (int i = 1; i <= user_input; i++)
    {
        cout << i << "\tI will NOT pay attention in class!" << endl;
    }

    return 0;
}