#include <iostream>

using namespace std;

class Cat
{
private:
    static int cat_count;
    char cat_name[50];

public:
    Cat()
    {
        cat_count++;
    }
    static int getCatCount();
    const char *getCatName() const
    {
        return cat_name;
    }

    void setCatName()
    {
        cout << "Enter cat name: " << endl;
        cin.getline(cat_name, 50);
    }
};

int Cat::cat_count = 0;

int Cat::getCatCount()
{
    return cat_count;
}

int main()
{

    Cat c1, c2;

    cout << Cat::getCatCount() << endl;
    c1.setCatName();
    c2.setCatName();

    cout << c1.getCatName() << endl;
    cout << c2.getCatName() << endl;

    Cat c3;
    cout << c3.getCatCount() << endl;

    return 0;
}