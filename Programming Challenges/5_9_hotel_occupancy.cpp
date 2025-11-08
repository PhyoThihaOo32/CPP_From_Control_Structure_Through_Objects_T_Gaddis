/*
This program calculates the occupancy rate for a hotel.
It asks for the number of floors, and for each floor (except the 13th),
it records how many rooms exist and how many are occupied.
It then displays total rooms, occupied rooms, empty rooms, and
the overall occupancy percentage.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num_floors,
        num_rooms,
        occupied_rooms,
        empty_rooms,
        total_rooms = 0,
        ttl_occ_rooms = 0,
        ttl_emty_rooms = 0;

    double per_room_occupied;

    cout << "Enter the number of floors in the hotel: ";
    cin >> num_floors;

    // Input validation for number of floors
    while (num_floors < 1)
    {
        cout << "Invalid input. Number of floors must be at least 1. Try again: ";
        cin >> num_floors;
    }

    // Loop through each floor
    for (int i = 1; i <= num_floors; i++)
    {
        if (i == 13)
        {
            cout << "Skipping floor 13 (traditionally omitted).\n";
            continue;
        }

        cout << "\n--- Floor " << i << " ---\n";
        cout << "Enter number of rooms on this floor: ";
        cin >> num_rooms;

        // Validate number of rooms
        while (num_rooms < 10)
        {
            cout << "Invalid input. Each floor must have at least 10 rooms. Try again: ";
            cin >> num_rooms;
        }

        cout << "Enter number of occupied rooms: ";
        cin >> occupied_rooms;

        // Validate occupied rooms
        while (occupied_rooms < 0 || occupied_rooms > num_rooms)
        {
            cout << "Invalid input. Occupied rooms must be between 0 and " << num_rooms << ". Try again: ";
            cin >> occupied_rooms;
        }

        empty_rooms = num_rooms - occupied_rooms;

        total_rooms += num_rooms;
        ttl_occ_rooms += occupied_rooms;
        ttl_emty_rooms += empty_rooms;
    }

    // Calculate occupancy rate
    per_room_occupied = (static_cast<double>(ttl_occ_rooms) / total_rooms) * 100.0;

    // Display results
    cout << fixed << showpoint << setprecision(2);
    cout << "\n---------------------------------------------\n";
    cout << "Hotel Occupancy Summary\n";
    cout << "---------------------------------------------\n";
    cout << "Total number of rooms:          " << total_rooms << endl;
    cout << "Number of occupied rooms:       " << ttl_occ_rooms << endl;
    cout << "Number of empty rooms:          " << ttl_emty_rooms << endl;
    cout << "Percentage of rooms occupied:   " << per_room_occupied << "%\n";
    cout << "---------------------------------------------\n";

    return 0;
}