/*
This program will read a student's four test scores as input, and calculate the average with
the lowest test score dropped.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// read the student's four test score into a array
void read_testscores(double[], int);
// calculate the total of the scores
double get_total(const double[], int);
// find the lowest score
double get_lowest_scores(const double[], int);
// display the test scores
void show_testscores(double[], int);

int main()
{

    const int SIZE = 4;
    double testscores[SIZE],
        lowest_testscore,
        total_testscore,
        adjusted_testscore,
        avg_testscore;

    // set up numeric output formatting
    cout << setprecision(2) << fixed << showpoint;

    // get the test score from the user
    read_testscores(testscores, SIZE);

    // get the total of the test score
    total_testscore = get_total(testscores, SIZE);

    // get the lowest test score
    lowest_testscore = get_lowest_scores(testscores, SIZE);

    // drop lowest test score
    adjusted_testscore = total_testscore - lowest_testscore;

    // calculate the final average test score
    avg_testscore = (adjusted_testscore / (SIZE - 1));

    // display the final average test score
    cout << "The final average test score is: " << avg_testscore << endl;

    return 0;
}

void read_testscores(double testscores[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter test score " << (i + 1) << " :";
        cin >> testscores[i];
    }
}

void show_testscores(double testscores[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << testscores[i] << " ";
    }
    cout << endl;
}

double get_total(const double testscores[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += testscores[i];
    }

    return total;
}

double get_lowest_scores(const double testscores[], int size)
{
    double lowest = testscores[0];
    for (int index = 1; index < size; index++)
    {
        if (testscores[index] < lowest)
            lowest = testscores[index];
    }

    return lowest;
}
