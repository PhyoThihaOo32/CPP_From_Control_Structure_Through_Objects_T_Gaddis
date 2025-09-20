/*
This progrom averages 3 test scores and it repeats as many times as user wishes.
*/

#include <iostream>

using namespace std;

int main()
{

    // define variables
    double score1, score2, score3, averages;
    char user_option;

    // let execute the statments
    do
    {
        // ask the user for scores
        cout << "Enter score 1:\t";
        cin >> score1;

        cout << "Enter score 2:\t";
        cin >> score2;

        cout << "Enter score 3:\t";
        cin >> score3;

        // calculate the average and display the result
        averages = (score1 + score2 + score3) / 3;
        cout << "Average: " << averages << endl;

        // ask users they want to run the program again
        cout << "Would you like to calculate your score again?(Y/N)" << endl;
        cin >> user_option;

    } while (user_option == 'Y' || user_option == 'y');

    cout << "Study hard, because the WiFi password of success is hidden in the books.” 📚💻✨" << endl;

    return 0;
}