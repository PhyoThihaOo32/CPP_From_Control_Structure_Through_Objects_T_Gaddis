/*
Menu driven program allow the user to determin the course of action by selecting it from a list of action.
This program calculate the charges for membership in a health club.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // user's Variables
    int choice;
    int months;
    double charges;

    // constants for fixed rates
    const double ADULT_RATE = 40.0,
                 CHILD_RATE = 20.0,
                 SENIOR_RATE = 30.0;

    // constants for memberships choices
    const int ADULT_CHOICE = 1,
              CHILD_CHOICE = 2,
              SENIOR_CHOICE = 3,
              QUIT_CHOICE = 4;

    // display the menu and get user input
    cout << "\tHealth Club Membership Menu\t\n"
         << "1. Standard Adult Membership Menu.\n"
         << "2. Child Membership.\n"
         << "3.Senior Citizen Membership.\n"
         << "4. Quit the Program.\n";
    cin >> choice;

    // set the numeric ouput formatting
    cout << setprecision(2) << showpoint << fixed;

    // respond the user menu selection

    if (cin.fail() || (choice < 1 || choice > 4))
    {
        cout << "Invalid Data and User Input." << endl;
    }
    else
    {
        cout << "Great! Please enter the months: ";
        cin >> months;
        if (choice == ADULT_CHOICE)
        {
            charges = months * ADULT_RATE;
            cout << "You have chosen the adult membership plan.\n"
                 << "Charges for " << months << " months: " << charges << " $." << endl;
        }
        else if (choice == CHILD_CHOICE)
        {
            charges = months * CHILD_RATE;
            cout << "You have chosen the child membership plan.\n"
                 << "Charges for " << months << " months: " << charges << " $." << endl;
        }

        else if (choice == SENIOR_CHOICE)
        {
            charges = months * SENIOR_RATE;
            cout << "You have chosen the senior membership plan.\n"
                 << "Charges for " << months << " months: " << charges << " $." << endl;
        }
        else if (choice == QUIT_CHOICE)
        {
            cout << "Thank you. We hope to see you again." << endl;
        }
    }

    return 0;
}

/*
cin.fail() is a function that checks whether the
last input operation failed (for example, due to invalid data types).
It returns true when:
    •	You try to input a character or string into a numeric variable
    •	The input buffer is messed up (wrong formatting, wrong type, etc.)
*/