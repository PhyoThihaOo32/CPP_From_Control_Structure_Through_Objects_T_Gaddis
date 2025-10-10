/*
Online Book Merchants offers premium customers 1 free book with every purchase of 5 or more books and offers 2 free books with every purchase of 8 or more books. It offers regular customers 1 free book
with every purchase of 7 or more books, and offers 2 free books with every purchase of 12 or more books.
Write a statement that assigns freeBooks the appropriate value based on the values of the
bool variable isPremiumCustomer and the int variable nbooksPurchased.

Additional Notes: isPremiumCustomer and nbooksPurchased should not be modified
*/

#include <iostream>

using namespace std;

int main()
{

    int freeBooks;
    bool isPremiumCustomer;
    char membership;
    int nbooksPurchased;

    cout << "Select your membership:\n1.Premium Customer.\n2.Regular Customer.\t";
    cin >> membership;

    cout << "How many books you are buying today? ";
    cin >> nbooksPurchased;

    membership == '1' ? isPremiumCustomer = true : isPremiumCustomer = false;

    freeBooks = (isPremiumCustomer ? (nbooksPurchased >= 8 ? 2 : (nbooksPurchased >= 5 ? 1 : 0)) : (nbooksPurchased >= 12 ? 2 : (nbooksPurchased >= 7 ? 1 : 0)));

    cout << "You get " << freeBooks << " freeBooks!" << endl;

    return 0;
}