#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

    ifstream inputFile("transactions7888.txt");

    string transcation_type;
    double amounts,
        balance = 0.0,
        deposits = 0.0,
        spending = 0.0;

    cout << fixed << showpoint << setprecision(2);

    if (!inputFile)
    {
        cout << "Error opening the file." << endl;
    }

    else
    {
        while (inputFile >> transcation_type)
        {
            inputFile >> amounts;
            balance += amounts;

            if (amounts > 0)
            {
                deposits += amounts;
            }
            else
            {
                spending += amounts;
            }

            // display the transcation sheet
            cout << left << setw(25) << transcation_type;
            cout << setw(10) << right << amounts;
            cout << setw(12) << balance;
            cout << setw(12) << deposits;
            cout << setw(12) << spending << endl;
        }
    }

    inputFile.close();

    return 0;
}