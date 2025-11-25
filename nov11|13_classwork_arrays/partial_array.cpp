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
void printGrades(double[], int[], char[], int);
void print_student_info(double[], int[], char[], int, int);

int main()
{

    // max number of students
    const int SIZE = 30;

    ifstream inputFile("enrolledCSC500.txt");

    double midterm_grade[SIZE] = {};
    char letter_grade[SIZE] = {};
    int student_id[SIZE] = {},
        search_id, // the student id that the user will type in to be used with linear search
        index;     // to store the index value return by the linear search
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
    printGrades(midterm_grade, student_id, letter_grade, student_count);

    cout << "Maximum midterm grade: " << max_grade << endl;
    cout << "Minimum midterm grade: " << min_grade << endl;
    cout << "Class average grade: " << class_avg_grade << " %" << endl;
    cout << "Number of passing grade: " << passing_grade << endl;
    cout << "Number of failing grade: " << failing_grade << endl;

    // linear search part
    cout << "Type in a student ID and you can see the student's info: ";
    cin >> search_id;

    index = linearSearch(student_id, search_id, student_count);

    if (index != -1)
    {
        print_student_info(midterm_grade, student_id, letter_grade, index, student_count);
    }
    else
    {
        cout << "The search id " << search_id << " is not in the database." << endl;
    }

    
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
        if (array[i] == value)
        {
            found = true;
            position = i;
        }
        i++;
    }
    return position;
}

void printGrades(double grades[], int student_id[], char letter_grade[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Student ID: " << student_id[i] << " has a midterm grade of "
             << grades[i] << " and letter grade is " << letter_grade[i] << endl;
    }
    cout << endl;
}

void print_student_info(double grades[], int student_id[], char letter_grade[], int index, int size)
{
    cout << "Student ID: " << student_id[index] << " has a midterm grade of "
         << grades[index] << " and letter grade is " << letter_grade[index] << endl;
}
