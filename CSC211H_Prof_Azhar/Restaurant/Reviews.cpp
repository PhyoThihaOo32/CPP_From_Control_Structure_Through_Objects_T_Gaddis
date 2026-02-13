#include "Reviews.h"
#include <iostream>
using namespace std;

void Reviews::inputReview()
{
    Review review;
    string comment;
    int rating;

    cout << "\nEnter rating (-1 to stop): ";
    cin >> rating;
    cin.ignore();

    while (rating >= 0)
    {
        cout << "Enter Comment: ";
        getline(cin, comment);

        review.setRatingAndComment(rating, comment);
        reviewList.push_back(review);

        cout << "\nEnter next rating (-1 to stop): ";
        cin >> rating;
        cin.ignore();
    }
}

void Reviews::printCommentsForRating(int rating) const
{
    bool found = false;
    for (int i = 0; i < reviewList.size(); i++)
    {
        if (rating == reviewList[i].getRating())
        {
            cout << "- " << reviewList[i].getComment() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No comments found for this rating.\n";
}

int Reviews::getAvgRating() const
{
    if (reviewList.empty())
        return 0;

    int totalRating = 0;
    for (int i = 0; i < reviewList.size(); i++)
        totalRating += reviewList[i].getRating();

    return totalRating / reviewList.size();
}