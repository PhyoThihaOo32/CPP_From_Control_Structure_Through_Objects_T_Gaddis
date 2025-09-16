/*
This program use "fall through" feature to catch both uppercase and lowercase letters entered by the user.
*/

#include <iostream>

using namespace std;

int main()
{

    char feedGrade;

    // get the grade of feed.
    cout << "Our pet food is avaliable in three grades:\n";
    cout << "A, B and C. Which do you want pricing for? " << endl;
    cin.get(feedGrade);

    // display the price
    switch (feedGrade)
    {
    case 'a':
    case 'A':
        cout << "30 cents per pound.\n";
        break;
    case 'b':
    case 'B':
        cout << "20 cents per pound.\n";
        break;
    case 'c':
    case 'C':
        cout << "15 cents per pound.\n";
        break;
    default:
        cout << "Shrewd! Don't have it." << endl;
    }

    return 0;
}