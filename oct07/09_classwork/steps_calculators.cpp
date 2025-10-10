#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int num_days;
    int num_steps;
    int total_steps = 0;
    int num_days_goal_met = 0;
    int step_goal;
    float avg_steps;

    cout << "How many days are you tracking your steps? ";
    cin >> num_days;

    cout << "What is your goal each day ?";
    cin >> step_goal;

    for (int i = 0; i < num_days; i++)
    {

        cout << "How many steps did you take on day # " << i << " ? ";
        cin >> num_steps;

        total_steps += num_steps;

        if (num_steps >= step_goal)
        {
            num_days_goal_met++;
        }
    }

    avg_steps = static_cast<float>(total_steps) / num_days;

    // set the numeric data format
    cout << setprecision(2) << fixed << showpoint;

    cout << "Your average steps are " << avg_steps << endl;
    cout << "You met your goal of tracking " << step_goal << " steps on "
         << num_days_goal_met << " days." << endl;

    return 0;
}