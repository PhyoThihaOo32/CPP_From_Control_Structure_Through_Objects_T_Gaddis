#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <iostream>
#include <string>

using namespace std;

class TextBook
{
private:
    string title,
        author,
        publisher;

public:
    TextBook()
    {
        set(" ", " ", " ");
    }

    TextBook(string t, string a, string p)
    {
        set(t, a, p);
    }

    // set function
    void set(string t, string a, string p)
    {
        title = t;
        author = a;
        publisher = p;
    }

    // print function
    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

#endif