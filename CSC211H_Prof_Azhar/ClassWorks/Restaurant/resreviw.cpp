#include <iostream>
#include "Restaurant.h"
using namespace std;

int main()
{
    Restaurant rest1("Pepito’s Kitchen", "Mexican");

    rest1.displayRestaurantInfo();
    rest1.inputReviews();
    rest1.showAverageRating();

    int searchRating;
    cout << "\nEnter a rating to see comments: ";
    cin >> searchRating;
    rest1.showCommentsForRating(searchRating);

    cout << "\nThank you for using the review system!" << endl;
    return 0;
}