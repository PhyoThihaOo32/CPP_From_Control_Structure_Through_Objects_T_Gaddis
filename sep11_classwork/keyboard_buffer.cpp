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

    int x, y;
    cout << "Type a number: "; // type floating point number like 4.5 and see what happen
    cin >> x;

    cout << "Type another number: ";
    cin >> y;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    /*
        1.	Variables
    •	x and y are declared as int.
    •	That means they can only store whole numbers (no decimals).
    2.	User input for x
    •	When you type, say 4.5, cin tries to put that into an int.
    •	C++ truncates (cuts off) the decimal part when storing into an integer.
    •	So x becomes 4.
    3.	What happens to the .5
    •	Input works like a stream.
    •	cin >> x; reads the 4 part and stops at the decimal point.
    •	The remaining .5 stays in the input buffer (waiting to be read next).
    4.	Next input for y
    •	When you do cin >> y;, C++ looks at the leftover .5.
    •	It tries to read it as an integer → it sees the decimal . and can’t match it to an int.
    •	So cin fails, and y doesn’t get assigned properly (it keeps its old/garbage value, or zero depending on compiler).
    */

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