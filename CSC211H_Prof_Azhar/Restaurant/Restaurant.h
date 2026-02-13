#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include "Reviews.h"
using namespace std;

class Restaurant
{
private:
    string name;
    string cuisineType;
    Reviews reviews; // composition: restaurant "has" reviews

public:
    Restaurant();
    Restaurant(string n, string c);

    void setName(string);
    void setCuisineType(string);

    string getName() const;
    string getCuisineType() const;

    void inputReviews();
    void displayRestaurantInfo() const;
    void showCommentsForRating(int) const;
    void showAverageRating() const;
};

#endif