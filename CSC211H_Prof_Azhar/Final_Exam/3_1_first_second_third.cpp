#include <iostream>
#include <string>

using namespace std;

class First
{
private:
    string word;

protected:
    int x;
    void check()
    {
        //cout << word;
    }

public:
    First(int x, string word) : x(x), word(word)
    {
    }
    void calc()
    {
    }
};

class Second : public First
{
private:
    char c;

protected:
    int y;

public:
    Second(int x, int y, string word, char c) : y(y), c(c), First(x, word)
    {
    }

    void fun()
    {
    }

    void calc(double d1, double d2)
    {
    }

    void doSom()
    {
        cout << "calling base class protected memeber :" << x << endl;
    }
};

class Third
{
private:
    int b;

protected:
    Second S;
    char z;

public:
    Third(int x, int y, int z, string word, char c, char cz) : S(y, z, word, c)
    {
        b = x;
        cz = z;
    }

    void print();
};

int main()
{

    Second sec(1, 2, "second", 's');

    // object of derived class calling base class protected member -> is not allowed
    // also can't call it own protected members fun and variables
    // sec.x -> not accessible
    // sec.y -> not accessible

    First object1(4, "RED");
    Second object2(6, 9, "Blue", 'S');
    Third object3(5, 3, 8, "Black", 'A', 'X');

    object1.calc();
    object2.calc(3, 3);
    object3.print();

    return 0;
}