/*
This program calculates and displays:
1. The distance an object falls due to gravity (d = 1/2 * g * t^2)
2. The kinetic energy of a moving object (KE = 1/2 * m * v^2)
3. Converts temperature from Fahrenheit to Celsius (C = 5/9 * (F - 32))
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double fallingDistance(int time);
double kineticEnergy(double mass, double velocity);
double toCelsius(double fahrenheit);
void showMenu();

int main()
{
    int user_time, user_choice;
    double mass, velocity, fahrenheit;

    cout << fixed << setprecision(2);

    do
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> user_choice;
        cout << endl;

        switch (user_choice)
        {
        case 1:
            // Falling distance
            cout << "Enter total fall time (in seconds): ";
            cin >> user_time;

            while (user_time < 0)
            {
                cout << "Invalid input. Time cannot be negative. Try again: ";
                cin >> user_time;
            }

            cout << "\nTime (s)\tDistance (m)\n";
            cout << "-------------------------\n";

            for (int i = 1; i <= user_time; i++)
            {
                cout << setw(5) << i << "\t\t" << setw(10) << fallingDistance(i) << endl;
            }
            cout << "\n-----------------------------------------\n";
            break;

        case 2:
            // Kinetic energy
            cout << "Enter the object mass (kg): ";
            cin >> mass;
            while (mass <= 0)
            {
                cout << "Invalid input. Mass must be positive. Try again: ";
                cin >> mass;
            }

            cout << "Enter the velocity (m/s): ";
            cin >> velocity;
            while (velocity < 0)
            {
                cout << "Invalid input. Velocity cannot be negative. Try again: ";
                cin >> velocity;
            }

            cout << "\nKinetic Energy: " << kineticEnergy(mass, velocity) << " joules\n";
            cout << "-----------------------------------------\n";
            break;

        case 3:
            // Fahrenheit to Celsius
            cout << "Enter temperature in Fahrenheit: ";
            cin >> fahrenheit;
            cout << "Temperature in Celsius: " << toCelsius(fahrenheit) << " °C\n";
            cout << "-----------------------------------------\n";
            break;

        case 4:
            cout << "Thank you for using the Physics Calculator. Goodbye!\n";
            break;

        default:
            cout << "Invalid input. Please choose between 1 and 4.\n";
            break;
        }

        cout << endl;

    } while (user_choice != 4);

    return 0;
}

// Calculates falling distance
double fallingDistance(int time)
{
    const double g = 9.8;
    return 0.5 * g * (time * time);
}

// Calculates kinetic energy
double kineticEnergy(double mass, double velocity)
{
    return 0.5 * mass * velocity * velocity;
}

// Converts Fahrenheit to Celsius
double toCelsius(double fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Displays menu
void showMenu()
{
    cout << "==============================\n";
    cout << "     PHYSICS CALCULATOR MENU\n";
    cout << "==============================\n";
    cout << "1. Calculate falling distance\n";
    cout << "2. Calculate kinetic energy\n";
    cout << "3. Convert Fahrenheit to Celsius\n";
    cout << "4. Exit\n";
    cout << "==============================\n";
}