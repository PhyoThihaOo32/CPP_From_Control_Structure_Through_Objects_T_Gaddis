/*
This program average three test scores
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const int HIGH_SCORE = 95;
    double score1, score2, score3, average_score;

    // Get the three score from the user
    cout << "Enter score1 score2 score3(seperated by a space): ";
    cin >> score1 >> score2 >> score3;

    // Calculate the average
    average_score = (score1 + score2 + score3) / 3;

    // Format the output
    cout << setprecision(3) << showpoint << fixed;

    // Congraguate the user if the avg_score is more than 95
    if (average_score > HIGH_SCORE)
    {
        cout << "Congragulation!" << endl;
    }

    cout << "Your average score is: " << average_score << endl;

    return 0;
}