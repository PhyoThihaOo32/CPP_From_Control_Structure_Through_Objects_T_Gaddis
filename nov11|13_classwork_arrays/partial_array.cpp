/*
This program is about Partial and Parallel Array.

1001 Alan Turing
9999 Bjarne Stroustrup
1234 Linus Torvalds
7890 James Gosling
9989 Dennis Ritchie
8754 Brian Kernighan
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

double find_average(double[], int);
double findMax(double[], int);
double findMin(double[], int);
int linearSearch(int[], int, int);

int main()
{

    // max number of students
    const int SIZE = 30;

    ifstream inputFile("enrolledCSC500.txt");

    double midterm_grade[SIZE] = {};
    char letter_grade[SIZE] = {};
    int student_id[SIZE] = {};
    string first_name[SIZE] = {};
    string last_name[SIZE] = {};
    double ttl_grade, class_avg_grade, max_grade, min_grade;

    // to count the number of students enrolled
    int student_count = 0, passing_grade = 0, failing_grade = 0;

    if (inputFile)
    {
        while (inputFile >> student_id[student_count])
        {
            inputFile >> first_name[student_count] >> last_name[student_count];
            student_count++;
        }
    }
    else
    {
        cout << "Error opening the file." << endl;
    }

    inputFile.close();

    // ask each student's test grade
    for (int i = 0; i < student_count; i++)
    {
        cout << "Enter the test grade for " << first_name[i] << " " << last_name[i] << " ?";
        cin >> midterm_grade[i];
        ttl_grade += midterm_grade[i];
        if (midterm_grade[i] >= 90)
        {
            letter_grade[i] = 'A';
            passing_grade++;
        }
        else if (midterm_grade[i] >= 80)
        {
            letter_grade[i] = 'B';
            passing_grade++;
        }
        else if (midterm_grade[i] >= 70)
        {
            letter_grade[i] = 'C';
            passing_grade++;
        }
        else if (midterm_grade[i] >= 60)
        {
            letter_grade[i] = 'D';
            passing_grade++;
        }
        else
        {
            letter_grade[i] = 'F';
            failing_grade++;
        }
    }

    // calculate the average grade
    class_avg_grade = find_average(midterm_grade, student_count);

    // find min and max
    max_grade = findMax(midterm_grade, student_count);
    min_grade = findMin(midterm_grade, student_count);

    // set output format
    cout << setprecision(2) << showpoint << fixed;

    // print out the student id and their letter grade
    for (int i = 0; i < student_count; i++)
    {
        cout << student_id[i] << " has a midterm grade of " << midterm_grade[i] << endl;
        cout << "and letter grade is " << letter_grade[i] << endl;
    }

    cout << "Maximum midterm grade: " << max_grade << endl;
    cout << "Minimum midterm grade: " << min_grade << endl;
    cout << "Class average grade: " << class_avg_grade << " %" << endl;
    cout << "Number of passing grade: " << passing_grade << endl;
    cout << "Number of failing grade: " << failing_grade << endl;

    return 0;
}

double find_average(double array[], int size)
{
    double total = 0;
    double avg;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }

    return avg = total / size;
}

double findMax(double array[], int size)
{
    double max_grade = array[0];

    // finding max and min grades
    for (int i = 1; i < size; i++)
    {

        if (array[i] > max_grade)
        {
            max_grade = array[i];
        }
    }

    return max_grade;
}

double findMin(double array[], int size)
{
    double min_grade = array[0];

    // finding max and min grades
    for (int i = 1; i < size; i++)
    {

        if (array[i] < min_grade)
        {
            min_grade = array[i];
        }
    }

    return min_grade;
}

int linearSearch(int array[], int value, int size)
{
    bool found = false;
    int position = -1;
    int i = 0;
    while (found == false && i < size)
    {
        if (array[i] = value)
        {
            found = true;
            position = i;
        }
        i++;
    }
    return position;
}
