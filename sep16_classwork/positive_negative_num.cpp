/*
This program check if the number is positive, negative or zero number.
*/

#include <iostream>

using namespace std;

int main()
{

    float user_num;

    // get user input
    cout << "What is your number? ";
    cin >> user_num;

    // facotoring
    cout << "This is " <<

        // check if the number is positive, negative or zero.

        ((user_num == 0) ? "zero" : ((user_num > 0) ? "positive" : "negative")) << " number" << endl;

    return 0;
}