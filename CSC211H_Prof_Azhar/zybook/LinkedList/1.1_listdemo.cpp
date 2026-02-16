#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{

    list<string> names;

    names.push_back("Tom");
    names.push_back("Diggie");
    names.push_back("Pepito Mucho");
    names.push_back("Jakie Robinson");

    // add value in forth place
    list<string>::iterator pos = names.begin();
    // auto pos = names.begin();

    pos++;
    pos++;
    pos++; // or just pos += 4;
    names.insert(pos, "Mr. 4th Element");

    // remove the value in second place
    pos = names.begin();
    pos++;

    names.erase(pos);

    // print all values
    for (pos = names.begin(); pos != names.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;

    // print all values with range-based loop
    for (const string &element : names)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}