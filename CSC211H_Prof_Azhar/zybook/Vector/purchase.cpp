/*
Use cin to read integer entryNumber from input until the next entryNumber read is equal to -1. If entryNumber is not equal to -1, use currPurchase's ReadDetails() function to read the purchase's option and food from input and append currPurchase to vector purchaseList.

Ex: If the input is:

1 A cucumber
2 B pear
3 C daikon
-1

then the output is:

Purchase option: A, Food: cucumber
Purchase option: B, Food: pear
Purchase option: C, Food: daikon
*/

#include <iostream>
#include <vector>
using namespace std;

class Purchase
{
public:
    void ReadDetails();
    void Print() const;

private:
    char option;
    string food;
};

void Purchase::ReadDetails()
{
    cin >> option;
    cin >> food;
}

void Purchase::Print() const
{
    cout << "Purchase option: " << option << ", Food: " << food << endl;
}

int main()
{
    vector<Purchase> purchaseList;
    Purchase currPurchase;
    int entryNumber;
    unsigned int i;

    cin >> entryNumber;
    while (entryNumber != -1)
    {
        currPurchase.ReadDetails();
        purchaseList.push_back(currPurchase);
    }

    for (i = 0; i < purchaseList.size(); ++i)
    {
        currPurchase = purchaseList.at(i);
        currPurchase.Print();
    }

    return 0;
}