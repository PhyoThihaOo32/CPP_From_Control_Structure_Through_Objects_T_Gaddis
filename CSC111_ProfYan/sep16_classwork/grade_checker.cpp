/*
grade is between 90 and 93, inclusive: grade >= 90 && grade <=93
user input is either 'Y/y' or 'N/n': user_input == 'Y' || user_input == 'y'
password is not abc1223: password != "abc123" / [ !(password == "abc123")]
first-ch is not a digit: 0 to 9.  !(first_ch > 47 && first_ch < 58) : first_ch < 48  || first_ch > 57:
Demorgan's Law: !(p && q) = !p || !q
                !(p || q) = !p && !q
*/

#include <iostream>

using namespace std;

int main()
{

    float grade;

    // ask user for grade
    cout << "Enter your grade: ";
    cin >> grade;

    // determine if he pass
    if (grade >= 60)
    {
        cout << "You passed!" << endl;
    }

    return 0;
}