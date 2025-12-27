/*
Students must either have GPA 3.5 or recommandation from their CSC211 professor and must have 40 credits.
This program check the requirements for intership from the sudents.
*/

#include <iostream>

using namespace std;

int main()
{

    int credits;
    float gpa;
    bool hasRecommendation;
    char recommendation_input;

    // ask for the credits
    cout << "How many credits do you have? ";
    cin >> credits;

    // ask for gpa
    cout << "What is your GPA? ";
    cin >> gpa;

    // ask for recommendation
    cout << "Do you have a recommendation from your CSC211 professor?(Y/N)";
    cin >> recommendation_input;

    // set flag
    hasRecommendation = (recommendation_input == 'Y' || recommendation_input == 'y' ? true : false);
    // recomendation_input = recommendation_input == 'Y' || recommendation_input == 'y';

    // determin the eligibility
    if (credits >= 40 && (hasRecommendation || gpa > 3.5))
    {
        cout << "You are eligible for this opportunity." << endl;
    }
    else
    {
        cout << "There may be other opportunities." << endl;
    }

    return 0;
}