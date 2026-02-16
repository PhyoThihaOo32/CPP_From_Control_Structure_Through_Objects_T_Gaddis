// This program removes every third element from a linked list

#include <iostream>
#include <list>
#include <string>

using namespace std;

void removeEveryThird(list<string> &);

int main()
{
    list<string> strListNames;
    strListNames.push_back("Pepito Mucho");
    strListNames.push_back("Milo");
    strListNames.push_back("Reiko Nicko");
    strListNames.push_back("India Masala");
    strListNames.push_back("Bird from Rio");
    strListNames.push_back("Nighly Hooker");
    strListNames.push_back("Charlie Parker");
    strListNames.push_back("Max Mad Must!");
    strListNames.push_back("Bella Lolla");
    strListNames.push_back("Oliver Trump");

    for (const auto names : strListNames)
    {
        cout << names << endl;
    }
    removeEveryThird(strListNames);

    cout << "After removed: " << endl;
    for (const auto names : strListNames)
    {
        cout << names << endl;
    }

    return 0;
}

void removeEveryThird(list<string> &strList)
{
    int count = 1;
    list<string>::iterator pos = strList.begin();
    while (pos != strList.end())
    {
        if (count == 3)
        {
            pos = strList.erase(pos);
            count = 1;
        }
        else
        {
            pos++;
            count++;
        }
    }
}