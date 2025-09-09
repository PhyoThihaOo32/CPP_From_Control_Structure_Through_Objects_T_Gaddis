/*
Use cin for single-word input (like numbers or one-word strings).
Use getline() for full-line input, especially when spaces matter (like full names, addresses, sentences, etc).
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string name;
    string city;

    cout << "Please enter your name: " << endl;
    getline(cin, name);

    cout << "Please enter the city you live in: " << endl;
    getline(cin, city);

    cout << "Hello " << name << "\n"
         << "You live in " << city << endl;

    return 0;
}