/*
Type casting allow you to perform manual data type conversion.
This program use type cast to avoid integer division.
*/

#include <iostream>

using namespace std;

int main()
{

    int books;       // number of books to read
    int months;      // Number of months spent reading
    double perMonth; // Average number of books per month

    cout << "How many books do you plan to read?" << endl;
    cin >> books;

    cout << "How many months will it take you to read them?" << endl;
    cin >> months;

    perMonth = static_cast<double>(books) / months;
    cout << "That's " << perMonth << " books per month." << endl;

    return 0;
}