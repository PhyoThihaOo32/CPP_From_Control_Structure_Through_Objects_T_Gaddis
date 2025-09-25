/*
This program display a menu and ask the user to make a selection.
Use can select the membership choice and program will calculate the charges based on membership.
This program use rewrite by using modular[divide and conquer] approach.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototype
void show_menu();
void show_charges(double, int);

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
        show_menu();
        cin >> user_choice;

        // validate user_choice
        while (user_choice < ADULT_CHOICE || user_choice > QUIT_CHOICE)
        {
            cout << "Please enter the valid input." << endl;
            cin >> user_choice;
        }

        if (user_choice != QUIT_CHOICE)
        {
            // ask for months
            cout << "Please enter the months [ to calculate the charges: ]: ";
            cin >> months;

            // validate the months input
            while (cin.fail())
            {
                cin.clear(); // Clear the error flag with cin.clear()
                cin.ignore(1000, '\n');
                cout << "Please enter the valid input: ";
                cin >> months;
            }

            // calculate the charges based on user_choice
            switch (user_choice)
            {
            case ADULT_CHOICE:
                cout << "Thank you for choosing adult membership plan." << endl;
                show_charges(ADULT_CHARGE, months);
                break;
            case CHILD_CHOICE:
                cout << "Thank you for choosing child membership plan." << endl;
                show_charges(CHILD_CHARGE, months);
                break;
            case SENIOR_CHOICE:
                cout << "Thank you for choosing senior membership plan." << endl;
                show_charges(SENIOR_CHARGE, months);
                break;
            default:
                cout << "We might not have this membership plan yet." << endl;
            }
        }

    } while (user_choice != QUIT_CHOICE);

    cout << "Thank you for visiting to our gym. Stay safe and stay fit!" << endl;

    return 0;
}

/*
This function show the display menu.
*/
void show_menu()
{

    // display the menu
    cout << "Welcome to the pure gym membership options.\n"
         << "1.Standard adult membership.\n"
         << "2.Child membership.\n"
         << "3.Senior membership.\n"
         << "4.Quit the program.\n"
         << "Please enter the number to choose the membership.(1-4).\n";
}

/*
This function calculate the charges based of rate of membership types and months and display the result.
*/

void show_charges(double membership_rate, int months)
{
    cout << "The total charges: " << (membership_rate * months) << endl;
}
