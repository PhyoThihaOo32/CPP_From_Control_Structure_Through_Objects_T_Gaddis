/*
without the break statement, the program "fall through" all of the statements below the one with the
matching case expression.
and this fall through capability can be is when you want the progream to branch to the same set of
statement for multiple case expressions.
*/

/*
This program is carefully constructed to use the "fall through" feature of the switch statment.
*/

#include <iostream>

using namespace std;

int main()
{

    int model_number;

    // get model number from the user
    cout << "Our TVs come in three models:\n"
         << "The 100, 200 and 300 models.\n"
         << "Please enter the model of your choice: ";
    cin >> model_number;

    if (model_number == 100 || model_number == 200 || model_number == 300)
    {
        cout << "The model has the following features.\n";
        switch (model_number)
        {
        case 300:
            cout << "Picture-in-a-picture capability." << endl;
        case 200:
            cout << "Remote control and stereo sound." << endl;
        case 100:
            cout << "Remote control." << endl;
            break;
        default:
            cout << "We don't have that model number." << endl;
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}