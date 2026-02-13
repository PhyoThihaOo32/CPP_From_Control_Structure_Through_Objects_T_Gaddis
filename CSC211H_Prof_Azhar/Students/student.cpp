#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student
{
private:
    string stuName;
    int stuId;
    float stuGpa;

public:
    Student()
    {
        stuName = "";
        stuId = 0;
        stuGpa = 0.0;
    }
    Student(string n, int i, float g) : stuName(n), stuId(i), stuGpa(g) {};

    void setName(string n) { stuName = n; }
    void setId(int id) { stuId = id; }
    void setGpa(float gpa) { stuGpa = gpa; }

    string getName() const { return stuName; }
    int getId() const { return stuId; }
    float getGpa() const { return stuGpa; }

    void displayStuInfo() const
    {
        cout << "Name: " << setw(10) << stuName << endl
             << "ID: " << setw(10) << stuId << endl
             << "GPA: " << setw(10) << stuGpa << endl;
    }
};

int main()
{

    return 0;
}