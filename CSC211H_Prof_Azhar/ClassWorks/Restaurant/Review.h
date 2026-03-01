#ifndef REVIEW_H
#define REVIEW_H

#include <string>
using namespace std;

class Review
{
private:
    int rating;
    string comment;

public:
    Review();
    Review(int r, string c);

    void setRatingAndComment(int, string);
    string getComment() const;
    int getRating() const;
};

#endif