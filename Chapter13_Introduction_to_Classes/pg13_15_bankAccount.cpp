#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

void displayMenu();
void makeDeposit(Account &);
void makeWithdraw(Account &);

int main()
{
    Account savings; // default account
    char choice;

    cout << fixed << showpoint << setprecision(2);

    do
    {
        displayMenu();
        cin >> choice;

        // validate input
        while (toupper(choice) < 'A' || toupper(choice) > 'G')
        {
            cout << "Invalid Input. Please choose from A to G: ";
            cin >> choice;
        }

        switch (toupper(choice))
        {
        case 'A':
            cout << "\nAccount Balance: $" << savings.getBalance() << endl;
            break;

        case 'B':
            cout << "\nNumber of Transactions: " << savings.getTransactions() << endl;
            break;

        case 'C':
            cout << "\nInterest Earned: $" << savings.getInterest() << endl;
            break;

        case 'D':
            makeDeposit(savings);
            break;

        case 'E':
            makeWithdraw(savings);
            break;

        case 'F':
            savings.addInterest();
            cout << "\nInterest added for this period.\n";
            break;

        case 'G':
            cout << "\nExiting program. Thank you!\n";
            break;
        }

        cout << "\n---------------------------------------\n";

    } while (toupper(choice) != 'G');

    return 0;
}

void displayMenu()
{
    cout << "\n=========== BANK ACCOUNT MENU ===========\n";
    cout << "A. Display Account Balance\n";
    cout << "B. Display Number of Transactions\n";
    cout << "C. Display Interest Earned\n";
    cout << "D. Make a Deposit\n";
    cout << "E. Make a Withdrawal\n";
    cout << "F. Add Interest for This Period\n";
    cout << "G. Exit Program\n";
    cout << "=========================================\n";
    cout << "Enter your choice: ";
}

void makeDeposit(Account &acc)
{
    double deposit;
    cout << "Enter deposit amount: ";
    cin >> deposit;

    acc.makeDeposit(deposit);
    cout << "Deposit successful!\n";
}

void makeWithdraw(Account &acc)
{
    double withdrawAmount;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;

    if (acc.withdraw(withdrawAmount))
        cout << "Withdrawal successful!\n";
    else
        cout << "Error: Withdrawal amount exceeds balance!\n";
}