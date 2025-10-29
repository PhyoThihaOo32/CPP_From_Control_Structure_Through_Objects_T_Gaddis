/*
This program will help order-entry operators look up product prices. The program should prompt
the user to enter a product number and will then display the tile, description and price of the product.
*/

#include <iostream>
#include <string>

using namespace std;

// const variables for the products of DLC
const int NUM_PROD = 9;
const int MIN_PROD = 914;
const int MAX_PROD = 922;

int getProd_num();
int binarySearch(const int[], int, int);
void displayProd(const string[], const string[], const double[], int);

int main()
{

    // array of the product title
    string prod_title[NUM_PROD] = {"Six Steps to Leadership", "Six Steps to Leadership",
                                   "The Road to Excellence", "Seven Lessons of Quality",
                                   "Seven Lessons of Quality", "Seven Lessons of Quality",
                                   "Teams Are Made, Not Born", "Leadership for the Future",
                                   "Leadership for the Future"};

    // array of the product description
    string prod_descp[NUM_PROD] = {"Book", "Audio CD", "DVD", "Book", "Audio CD", "DVD",
                                   "Book", "Book", "Audio CD"};

    // array of Unit price
    double prod_price[NUM_PROD] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95};

    // array of product numbers
    int prod_num[NUM_PROD] = {914, 915, 916, 917, 918, 919, 920, 921, 922};

    int user_prodnum; // to hold the product number
    int prod_index;   // to hold the product index

    // get user input
    user_prodnum = getProd_num();

    // find the number using binary search
    prod_index = binarySearch(prod_num, NUM_PROD, user_prodnum);

    // display the result
    displayProd(prod_title, prod_descp, prod_price, prod_index);

    return 0;
}

// this function will ask the product number from the user and return the num
int getProd_num()
{
    int user_num;

    do
    {

        // promt the user the enter the product number looking for
        cout << "Enter the product number: [we currenly have prod_num "
             << MIN_PROD << " to " << MAX_PROD << " ].\n";
        cin >> user_num;
    }

    // validate the user input
    while (user_num < MIN_PROD || user_num > MAX_PROD);

    return user_num;
}

// binary search algorithm

int binarySearch(const int prod_ID[], int size, int prod_num)
{

    // setting up the index of the searched array
    int first_index = 0,
        last_index = size - 1,
        middle_index,
        position = -1;
    bool isFound = true; // flag

    while (first_index <= last_index && isFound)
    {
        middle_index = (first_index + last_index) / 2;
        if (prod_ID[middle_index] == prod_num)
        { // when the prod_num is found at middle position
            isFound = false;
            return position = middle_index;
        }
        else
        {
            if (prod_num < prod_ID[middle_index])
            { // if the prod_num is in lower half
                last_index = middle_index - 1;
            }
            else
            { // if the prod_num is higher half
                first_index = middle_index + 1;
            }
        }
    }
    // if not found return -1
    return position;
}

void displayProd(const string title[], const string descp[], const double price[], int index)
{

    cout << "Product Tile: " << title[index] << endl;
    cout << "Product Description: " << descp[index] << endl;
    cout << "Product Price: " << price[index] << endl;
}