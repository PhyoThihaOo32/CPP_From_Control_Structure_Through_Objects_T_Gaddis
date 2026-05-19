#include <iostream>

using namespace std;

class Employee
{
private:
    int *numEmployee;
    int *empId;
    double *totalHour;

public:
    Employee(int num)
    {
        numEmployee = new int(num); // create dynamic variable for num of employee and set it with num value

        empId = new int[num];
        totalHour = new double[num];

        for (int i = 0; i < num; i++)
        {
            empId[i] = 0;
            totalHour[i] = 0;
        }
    }

    void readEmployeeInfo()
    {
        for (int i = 0; i < *numEmployee; i++)
        {
            cout << "Enter ID for Employee " << i + 1 << " :" << endl;
            cin >> empId[i];

            cout << "Enter total hours worked by Employee " << i + 1 << " :" << endl;
            cin >> totalHour[i];
        }
    }

    void printInfo() const
    {
        for (int i = 0; i < *numEmployee; i++)
        {
            cout << "Employee ID : " << empId[i] << endl;
            cout << "Total Hours: " << totalHour[i] << endl;
            if (totalHour[i] >= 40)
            {
                cout << "FULL TIME EMPLOYEE" << endl;
            }
            else
            {
                cout << "PART TIME EMPLOYEE" << endl;
            }
        }
    }
    ~Employee()
    {
        delete numEmployee;
        delete[] empId;
        delete[] totalHour;

        numEmployee = nullptr;
        empId = nullptr;
        totalHour = nullptr;
    }
};
