/*
This program ask the user how many days they're tracking their steps
For each day, the program asks the user to type in the number of steps they took that day.
Find the total number of steps.
Find the average steps for each day.
When you've finished, go back to modify your program and ask them for their daily goal.
Your program will count the number of days the user met their daily goal.
*/

#include <iostream>

using namespace std;

int main()
{

    // variables
    int num_steps,
        total_num_steps = 0,
        avg_num_steps,
        num_days,
        daily_goal,
        daily_goal_count = 0;

    // ask user how many continuous days they have been tracing their steps
    cout << "How many continuous days they have been tracing their steps? ";
    cin >> num_days;

    // get the number of steps for each days
    for (int i = 1; i <= num_days; i++)
    {
        cout << "Enter the number of steps for day" << i << ": ";
        cin >> num_steps;

        // get total number of steps
        total_num_steps += num_steps;
    }

    // calculate the average steps
    avg_num_steps = total_num_steps / num_days;

    // display the total and avg steps
    cout << "Total number of steps:\t" << total_num_steps << endl;
    cout << "Average number of steps:\t" << avg_num_steps << endl;

    return 0;
}
