#include "Restaurant.h"
#include <iostream>
using namespace std;

Restaurant::Restaurant() : name(""), cuisineType("") {}

Restaurant::Restaurant(string n, string c) : name(n), cuisineType(c) {}

void Restaurant::setName(string n) { name = n; }
void Restaurant::setCuisineType(string c) { cuisineType = c; }

string Restaurant::getName() const { return name; }
string Restaurant::getCuisineType() const { return cuisineType; }

void Restaurant::inputReviews()
{
    cout << "\n--- Enter reviews for " << name << " ---" << endl;
    reviews.inputReview();
}

void Restaurant::displayRestaurantInfo() const
{
    cout << "\nRestaurant: " << name << endl;
    cout << "Cuisine Type: " << cuisineType << endl;
}

void Restaurant::showCommentsForRating(int rating) const
{
    cout << "\nComments for rating " << rating << ":\n";
    reviews.printCommentsForRating(rating);
}

void Restaurant::showAverageRating() const
{
    cout << "\nAverage rating for " << name << ": "
         << reviews.getAvgRating() << endl;
}