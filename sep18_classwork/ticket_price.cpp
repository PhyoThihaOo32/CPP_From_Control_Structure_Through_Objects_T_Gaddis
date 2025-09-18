/*
This program ask the user for their age and print out the ticket price.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // constant for discout_rate
    const float DISCOUNT_RATE = 0.33;

    unsigned age;
    float ticket_price;

    // calculate the discout ticket price
    float regular_ticket_price = 20;
    float minor_ticket_price = regular_ticket_price - (regular_ticket_price * DISCOUNT_RATE);

    // ask user age
    cout << "What is your age? ";
    cin >> age;

    // check if user is adult or minor
    cout << ((age < 18) ? "Minor" : "Adult") << endl;

    // set the ticket price and print it out
    ticket_price = (age >= 18) ? regular_ticket_price : minor_ticket_price;

    cout << setprecision(2) << showpoint << fixed << "Ticket price: " << ticket_price << " $" << endl;

    return 0;
}