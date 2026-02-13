#include "Review.h"

Review::Review() : rating(-1), comment("") {}
Review::Review(int r, string c) : rating(r), comment(c) {}

void Review::setRatingAndComment(int r, string c)
{
    rating = r;
    comment = c;
}

string Review::getComment() const { return comment; }
int Review::getRating() const { return rating; }