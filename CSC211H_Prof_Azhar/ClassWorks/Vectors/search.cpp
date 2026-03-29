/*
Program Description:

Write a program that reads a list of integers from input and prints
only those values that are less than or equal to a given threshold.

Input Format:
1. First input: an integer n → number of values in the list
2. Next input: n integers → the list of numbers
3. Last input: an integer → threshold value

Program Requirements:
- Store the n integers (using vector or array)
- Compare each value with the threshold
- Output only the values that are <= threshold
- Each output value must be followed by a comma (including the last one)

Example Input:
5
50 60 140 200 75
100

Explanation:
- n = 5 → total 5 numbers
- List = 50, 60, 140, 200, 75
- Threshold = 100
- Values <= 100 → 50, 60, 75

Expected Output:
50,60,75,

Note:
- Do NOT skip the comma after the last element
- This type of filtering is similar to real-world applications
  like filtering products by price (e.g., Amazon)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numEle;

    cout << "Enter the number of Elements to store in vector." << endl;
    cin >> numEle;

    // delcare vector of int with numEle
    vector<int> numbers(numEle);

    // use iterator to loop
    int i = 1;
    for (auto it = numbers.begin(); it != numbers.end(); it++, i++)
    {
        cout << "Enter Element " << i << " :";
        cin >> *it;
    }

    int threshold;
    cout << "Enter Threshold: ";
    cin >> threshold;

    for (int num : numbers)
    {
        if (num < threshold)
        {
            cout << num << ", ";
        }
    }
    cout << endl;

    return 0;
}