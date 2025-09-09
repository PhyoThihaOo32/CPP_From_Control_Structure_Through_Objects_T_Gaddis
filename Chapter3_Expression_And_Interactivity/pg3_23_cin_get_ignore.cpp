/*
This program demostrate the use of cin/ cin.get/cin.ignore
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int age;
    string name;
    char enter;

    cout << "Enter your name >> " << endl;
    getline(cin, name);
    cout << "Enter your age >> " << endl;
    cin >> age;
    cin.ignore(); // skip the newline character
    cout << "Press Enter." << endl;
    cin.get(enter).ignore();

    while (enter != '\n')
    {
        cout << "You didn't Enter?" << endl;
        cin.get(enter).ignore();
    }

    cout << "Name:\t " << name << "\n"
         << "Age:\t " << age << endl;

    return 0;
}