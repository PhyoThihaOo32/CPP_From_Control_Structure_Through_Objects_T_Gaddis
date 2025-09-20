/*
This program toggles the value of the bool variable onOffSwitch. That is, if onoffSwitch is false, its value is changed to true; if onoffSwitch is true,
its value is changed to false.
*/

#include <iostream>

using namespace std;

int main()
{

    bool OnOffSwitch;

    cout << "Toggles the Switch.\n1 is on.\n0 is off.";
    cin >> OnOffSwitch;

    cout << "You switch it to " << OnOffSwitch << endl;

    OnOffSwitch = !OnOffSwitch;

    cout << "But switch back to " << OnOffSwitch << endl;
}