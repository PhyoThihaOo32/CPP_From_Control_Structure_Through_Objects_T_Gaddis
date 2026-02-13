/*
The program below declares a vector groceryList, which is initially empty.
As the user enters grocery items one at a time, the program uses push_back()
to append the items to the list. When done, the user can go shopping, and is
presented one list item at a time (which the user presumably finds and places in a shopping cart).
The program uses back() to get each item from the list and pop_back() to remove the item from the list.
When the list is empty, shopping is finished.

Note that because the program removes items from the end of the list, the items are presented
in reverse order.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    vector<string> groceryList;
    string input;
    string items;

    cout << "Plase Type the grocery Item into Cart. Type q/Q to quit." << endl;
    getline(cin, input);
    while (input != "q" && input != "Q")
    {
        groceryList.push_back(input);
        cout << "Plase Type the grocery Item into Cart. Type q/Q to quit." << endl;
        getline(cin, input);
    }

    // user can check out the item in reverse order by pressing any keys and q to stop
    cout << "Press any key to take out the item in reverse order. And q/Q to stop." << endl;
    cin >> input;
    while (input != "Q" && input != "q")
    {
        items = groceryList.back(); // Returns vector's last element. Vector is unchanged.
        groceryList.pop_back();     // void pop_back(); Removes the last element.
        cout << "Item: " << items << endl;
        cout << "Press any key to take out the item in reverse order. And q/Q to stop." << endl;
        cin >> input;
        if (groceryList.size() == 0)
        {
            cout << "Cart is empty." << endl;
            break;
        }
    }

    return 0;
}