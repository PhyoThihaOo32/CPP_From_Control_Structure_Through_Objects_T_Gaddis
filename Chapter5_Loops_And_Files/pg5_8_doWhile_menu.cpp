/*
This program display a menu and ask the user to make a selection.
Use can select the membership choice and program will calculate the charges based on membership.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // constants for menu choice
    const int ADULT_CHOICE = 1,
              CHILD_CHOICE = 2,
              SENIOR_CHOICE = 3,
              QUIT_CHOICE = 4;
    // constant for membership charges
    const double ADULT_CHARGE = 40.0,
                 CHILD_CHARGE = 20.0,
                 SENIOR_CHARGE = 30.0;

    // variable for the program
    int user_choice;
    int months;
    double charges;

    // set the numeric ouput format
    cout << fixed << showpoint << setprecision(2);

    do
    {
        // display the menu
        cout << "Welcome to the pure gym membership options.\n"
             << "1.Standard adult membership.\n"
             << "2.Child membership.\n"
             << "3.Senior membership.\n"
             << "4.Quit the program.\n"
             << "Please enter the number to choose the membership.(1-4).\n";
        cin >> user_choice;

        // validate the menu selection
        while (!(user_choice >= ADULT_CHOICE && user_choice <= QUIT_CHOICE))
        {
            cout << "Please enter the valid menu choice.\n";
            cin >> user_choice;
        }

        if (user_choice != QUIT_CHOICE)
        {
            // ask user for months
            cout << "Please continue enter the months: " << endl;
            cin >> months;

            // process user choice  and calculate the memebership fees
            switch (user_choice)
            {
            case ADULT_CHOICE:
                cout << "Thank you for choosing adult membership plan." << endl;
                charges = ADULT_CHARGE * months;
                break;
            case CHILD_CHOICE:
                cout << "Thank you for choosing child membership plan." << endl;
                charges = CHILD_CHARGE * months;
                break;
            case SENIOR_CHOICE:
                cout << "Thank you for choosing senior membership plan." << endl;
                charges = SENIOR_CHARGE * months;
                break;
            default:
                cout << "Unexpected Error.\n";
            }

            // dispaly the the result
            cout << "The total charges: " << charges << endl;
        }

    } while (user_choice != QUIT_CHOICE);

    cout << "Thank you for visiting our gym.\n"
         << endl;

    return 0;
}