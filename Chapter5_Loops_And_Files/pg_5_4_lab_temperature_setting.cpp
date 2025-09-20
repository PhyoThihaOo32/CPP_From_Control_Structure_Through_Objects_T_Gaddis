/*
This program assists a technician in the process of checking a substance's temperature.
- technician must check the temp every 15 minutes.
- temperature does not exceed 102.5 degrees Celsius.
- if highter - turn down the thermostat and wait 5 min - check again.
- repeat if the temperature does not exceed 102.5 C.
*/

#include <iostream>

using namespace std;

int main()
{

    // temperature setting for a substance
    const double MAX_TEMP = 102.5;
    const int MAX_COUNT = 5;

    double current_temp;
    bool isTurnOn;

    // ask the user  to enter the current temperature
    cout << "Please enter the current temperature: " << endl;
    cin >> current_temp;

    // check if the temp is higher than max_temp. If so, tell the user to follow the steps.
    while (current_temp > MAX_TEMP)
    {
        cout << "Please Turn down the thermostat.\nTo off press 0.\nTo on press 1.\n";
        cin >> isTurnOn;
        int count = 0;
        while (isTurnOn && count < MAX_COUNT)
        {
            cout << "\aPlease turn off the thermostat.";
            cin >> isTurnOn;
            count++;
        }
        if (count == MAX_COUNT)
        {
            cout << "Thermostat automatically turn off.";
            isTurnOn = false;
        }
        cout << "Now please wait for 5 minute.\nCheck the temperature again.\nEnter the current temperature. ";
        cin >> current_temp;
    }

    cout << "Current Temperature is now: " << current_temp << " and is acceptable." << endl;
    cout << "Please check again in 15 minutes." << endl;

    return 0;
}