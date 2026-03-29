/*

Program Description:

Write a program that reads a list of words and outputs each word
along with its frequency (how many times it appears in the list).

Input Format:
1. First input: an integer n → number of words (n < 20)
2. Next input: n words (strings)

Program Requirements:
- Store all words in a vector of strings
- Use another vector to store the frequency of each word
- For each word in the list, count how many times it appears
- Output each word followed by its frequency

Output Format:
word - frequency

Important Notes:
- Output should follow the same order as input
- Duplicate words should still be printed each time
- Matching is case-sensitive (e.g., "Mark" and "mark" are different)
- Use two vectors:
    • vector<string> → to store words
    • vector<int> → to store frequencies

Example Input:
5
hey hi Mark hi mark

Example Output:
hey - 1
hi - 2
Mark - 1
hi - 2
mark - 1
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    int numWords;

    cout << "Enter Number of Words: ";
    cin >> numWords;

    vector<string> words(numWords);
    vector<int> frequency;

    // get words for user
    int i = 1;
    for (auto it = words.begin(); it != words.end(); it++, i++)
    {
        cout << "Enter Words " << i << " :";
        cin >> *it;
    }

    // // test - display words
    // for (string s : words)
    // {
    //     cout << s << endl;
    // }

    for (int i = 0; i < words.size(); i++)
    {
        int count = 0; // to count the words
        string check = words.at(i);
        for (int j = 0; j < words.size(); j++)
        {
            if (check == words[j])
            {
                count++;
            }
        }
        frequency.push_back(count);
    }

    for (int i = 0; i < numWords; i++)
    {
        cout << words.at(i) << " - " << frequency.at(i) << endl;
    }

    return 0;
}
