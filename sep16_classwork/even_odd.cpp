/*
This program ask the positive integer number from the user and check the number is even or odd.
*/

#include <iostream>

using namespace std;

int main()
{

    unsigned user_num;

    // ask the number from the user.
    cout << "Enter a positive integer number: ";
    cin >> user_num;

    // factoring out
    cout << "Your nubmer " << user_num << " is";

    // check if the number is even or odd.
    if (user_num % 2 == 0)
    {
        cout << " even." << endl;
    }
    else
    {
        cout << " odd." << endl;
    }

    return 0;
}