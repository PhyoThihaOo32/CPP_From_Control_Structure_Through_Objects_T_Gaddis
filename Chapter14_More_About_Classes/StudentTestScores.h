#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H

#include <string>
#include <iostream>
using namespace std;

// Constant for default test score initialization
const double DEFAULT_SCORE = 0.0;

class StudentTestScores
{
private:
    string name;        // Student name
    double *testScores; // Pointer to a dynamic array of test scores
    int numTestScores;  // Number of scores in the array

    // Helper function to allocate and initialize the array
    void createTestScoresArray(int size)
    {
        numTestScores = size;
        testScores = new double[size];

        // Initialize all scores to default
        for (int i = 0; i < size; i++)
        {
            testScores[i] = DEFAULT_SCORE;
        }
    }

public:
    // 1️⃣ Constructor
    StudentTestScores(string sName, int numTests)
    {
        name = sName;
        createTestScoresArray(numTests);
    }

    // 2️⃣ Copy Constructor (Deep Copy)
    StudentTestScores(const StudentTestScores &obj)
    {
        cout << "Copy constructor called for " << obj.name << endl;
        name = obj.name;
        numTestScores = obj.numTestScores;

        // Allocate new memory for the new object
        testScores = new double[numTestScores];

        // Deep copy of the array
        for (int i = 0; i < numTestScores; i++)
        {
            testScores[i] = obj.testScores[i];
        }
    }

    // 3️ Destructor — clean up dynamic memory
    ~StudentTestScores()
    {
        cout << "🧹 Destructor called for " << name << endl;
        delete[] testScores;
        testScores = nullptr;
    }

    // 4️⃣ Mutator (setter) functions
    void setName(string s)
    {
        name = s;
    }

    void setTestScore(double score, int index)
    {
        if (index >= 0 && index < numTestScores)
            testScores[index] = score;
        else
            cout << "⚠️ Invalid index.\n";
    }

    // 5️⃣ Accessor (getter) functions
    string getName() const { return name; }

    int getNumTestScores() const { return numTestScores; }

    double getTestScore(int index) const
    {
        if (index >= 0 && index < numTestScores)
            return testScores[index];
        else
        {
            cout << "⚠️ Invalid index.\n";
            return -1;
        }
    }

    // operator functions
    // overloaded = operator
    StudentTestScores &operator=(const StudentTestScores &rhs)
    {
        cout << "🧩 operator= called for " << rhs.name << endl;

        // 1️⃣ Handle self-assignment (very important)
        if (this == &rhs)
            return *this;

        // 2️⃣ Free existing dynamic memory
        delete[] testScores;

        // 3️⃣ Deep copy data from rhs
        name = rhs.name;
        numTestScores = rhs.numTestScores;
        testScores = new double[numTestScores];
        for (int i = 0; i < numTestScores; i++)
            testScores[i] = rhs.testScores[i];

        // 4️⃣ Return *this by reference
        return *this;
    }
    // student1 = student2;
    // student1.operator=(student2);
};

#endif