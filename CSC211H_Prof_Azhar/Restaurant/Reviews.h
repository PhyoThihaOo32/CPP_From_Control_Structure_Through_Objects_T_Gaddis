#ifndef REVIEWS_H
#define REVIEWS_H

#include "Review.h"
#include <vector>
using namespace std;

class Reviews
{
private:
    vector<Review> reviewList;

public:
    void inputReview();
    int getAvgRating() const;
    void printCommentsForRating(int) const;
};

#endif