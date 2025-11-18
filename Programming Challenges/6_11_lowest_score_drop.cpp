/*
This program calculates the average of five test scores,
dropping the lowest score before computing the average.
*/

#include <iostream>
using namespace std;

// Function prototypes
void getScore(int &);
int findLowest(int, int, int, int, int);
void calAverage(int, int, int, int, int);

int main()
{
    int test_score1, test_score2, test_score3, test_score4, test_score5;

    // Get 5 test scores from user
    getScore(test_score1);
    getScore(test_score2);
    getScore(test_score3);
    getScore(test_score4);
    getScore(test_score5);

    cout << "\nEntered scores: "
         << test_score1 << ", " << test_score2 << ", " << test_score3 << ", "
         << test_score4 << ", " << test_score5 << endl;

    // Display average after dropping lowest
    calAverage(test_score1, test_score2, test_score3, test_score4, test_score5);

    return 0;
}

// Function to get a valid score from the user
void getScore(int &score)
{
    do
    {
        cout << "Enter a test score (0–100): ";
        cin >> score;
        if (score < 0 || score > 100)
            cout << "Invalid input. Try again.\n";
    } while (score < 0 || score > 100);
}

// Function to find the lowest of five scores
int findLowest(int s1, int s2, int s3, int s4, int s5)
{
    int lowest = s1;
    if (s2 < lowest)
        lowest = s2;
    if (s3 < lowest)
        lowest = s3;
    if (s4 < lowest)
        lowest = s4;
    if (s5 < lowest)
        lowest = s5;
    return lowest;
}

// Function to calculate and display the average of the top 4 scores
void calAverage(int s1, int s2, int s3, int s4, int s5)
{
    int lowest = findLowest(s1, s2, s3, s4, s5);
    int total = (s1 + s2 + s3 + s4 + s5) - lowest;
    double avg = total / 4.0;

    cout << "Lowest score dropped: " << lowest << endl;
    cout << "Average of top 4 scores: " << avg << endl;
}