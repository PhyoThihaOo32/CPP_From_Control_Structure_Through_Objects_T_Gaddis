// resizing vector
// https://www.cplusplus.com/reference/vector/vector/
#include <iostream>
#include <vector>
using namespace std;
void setMyVector()
{
    vector<int> myvector;
    int x;

    // set some initial content:
    for (int i = 1; i < 10; i++)
    {
        cout << "Enter a value" << endl;
        cin >> x;
        myvector.push_back(x);
    }
    myvector.at(3) = 0;

    // myvector.resize(5);
    //  myvector.resize(8,100);
    // myvector.resize(12);
    myvector.erase(myvector.begin() + 3);
    // myvector.erase (myvector.begin(),myvector.begin()+3);
    myvector.pop_back();

    cout << "myvector contains:";
    for (int i = 0; i < myvector.size(); i++)
        cout << ' ' << myvector[i];
    cout << '\n';
}

void experimentVector()
{

    vector<int> myvector(3, 100);
    vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300); // insert 300 to first 2 position

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
    /*
    // "it" no longer valid, get a new one:
    it = myvector.begin();


    std::vector<int> anothervector (2,400);
    myvector.insert
    (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    */
}

int main()
{

    setMyVector();
    // experimentVector();

    return 0;
}
