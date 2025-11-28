/*
This program safely collects user input for ID number, name, age, and income.
It demonstrates the use of cin.getline() with character arrays to avoid
input buffer issues caused by mixing cin >> with cin.get() or cin.getline().

Key functions/concepts used:
 - cin.getline() → reads an entire line including spaces
 - atoi() → converts a C-string to an integer
 - atof() → converts a C-string to a floating-point number
 - showpoint, fixed, setprecision() → for formatted floating-point output
*/

#include <iostream>
#include <cstdlib> // for atoi() and atof()
#include <iomanip> // for formatting output

using namespace std;

int main()
{
    // Define constants for input sizes
    const int INPUT_SIZE = 81;
    const int NAME_SIZE = 30;

    // Declare character arrays for string input
    char input[INPUT_SIZE];
    char name[NAME_SIZE];

    // Declare pointer for name and variables for numeric data
    char *charPtr_name = nullptr;
    int idNumber, age;
    double income;

    // 🧮 Get the user ID number
    cout << "What is your ID number?" << endl;
    cin.getline(input, INPUT_SIZE); // Reads entire line safely
    idNumber = atoi(input);         // Convert to integer

    // 👤 Get the user name
    cout << "What is your name?" << endl;
    cin.getline(name, NAME_SIZE); // Reads full name (with spaces)
    charPtr_name = name;          // Pointer assigned to name array

    // 🎂 Get the user age
    cout << "How old are you?" << endl;
    cin.getline(input, INPUT_SIZE); // Read as string first
    age = atoi(input);              // Convert to integer

    // 💵 Get the user annual income
    cout << "What is your annual income?" << endl;
    cin.getline(input, INPUT_SIZE); // Read as string first
    income = atof(input);           // Convert to floating-point

    // 💬 Display the formatted output
    cout << fixed << showpoint << setprecision(2); // Format floating numbers
    cout << "\n--- User Information Summary ---\n";
    cout << "Name: " << charPtr_name << endl;
    cout << "ID Number: " << idNumber << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "Annual Income: $" << income << endl;
    cout << "---------------------------------\n";

    return 0;
}

/*
⚠️ Notes:
- Using cin >> followed by cin.get() or cin.getline() causes problems
  because cin >> leaves the newline character in the input buffer.
- The next input function (cin.getline) sees '\n' first and stops immediately.
- To avoid that, this program uses cin.getline() consistently for all inputs.
*/