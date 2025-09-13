/*
keyboard buffer - A keyboard buffer is a small section of computer memory
that temporarily stores keystrokes before the computer is ready to process them, ensuring no input is lost.
cin - ignore all leading white spaces
- when the user types input, they press Enter when finished. This leaves a newline in the keyborad buffer.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    // demostration 1

    // int x, y;
    // cout << "Type a number: ";
    // cin >> x;

    // cout << "Type another number: ";
    // cin >> y;

    // cout << "x: " << x << endl;
    // cout << "y: " << y << endl;

    // demostration 2

    int age;
    string city;

    cout << "What is your age? " << endl;
    cin >> age;

    // flushing out the keyboard buffer
    cin.ignore();

    cout << "What is the name of your city? " << endl;
    // cin >> city;
    getline(cin, city); // function to get the whole line of input

    cout << "Your age is " << age << endl;
    cout << "You live in " << city << endl;

    return 0;
}