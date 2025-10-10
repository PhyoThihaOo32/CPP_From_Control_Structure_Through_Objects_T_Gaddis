/*
This program initialize the string array.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    const int ARRAY_SIZE = 5;
    string plants_array[ARRAY_SIZE] = {"Rose 🌹",
                                       "Sunflower 🌻",
                                       "Tulip 🌷",
                                       "Bamboo 🎋",
                                       "Cactus 🌵"};

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << plants_array[i] << endl;
    }

    return 0;
}