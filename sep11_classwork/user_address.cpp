/*
This program demostrate use of cin/ getline/ cin.ignore() - and keyboard buffer.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    unsigned st_number, zip_code;
    string st_name, city;
    char state_abbrev1, state_abbrev2;

    // Ask user information - street number
    cout << "Enter street number:\t";
    cin >> st_number;
    cin.ignore();

    // Ask user street name
    cout << "Enter street name:\t";
    getline(cin, st_name);

    // Ask user city
    cout << "Enter city:\t";
    getline(cin, city);

    // Ask user state abbravation
    cout << "Enter state abbravation1:\t";
    cin.get(state_abbrev1);

    cout << "Enter state abbravation2:\t";
    cin >> state_abbrev2;

    // Ask zipcode
    cout << "Enter zipcode:\t";
    cin >> zip_code;

    // print the address
    cout << "Address:\t" << st_number << " "
         << st_name << ", " << city << ", "
         << state_abbrev1 << state_abbrev2 << ", " << zip_code << endl;

    return 0;
}