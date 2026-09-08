#include <iostream>
#include <string>
#include "arrayListType.h"

using namespace std;

int main(){

    // creating the two arrayListType - int and string
    arrayListType<int> intList(10);
    arrayListType<string> stringList(10);

    // insert 
    cout << "Inserting the element to the intList and stringList" << endl;
    cout << endl;
    intList.insert(99);
    stringList.insert("Phyo");
    intList.insert(100);
    stringList.insert("Thiha");
    intList.insert(101);
    stringList.insert("Oo");

    // print 
    cout << "Printing the intList and stringList" << endl;
    intList.print();
    stringList.print();
      cout << endl;

    // delete
    cout << "Deleting the Lists" << endl;
    intList.clearList();
    stringList.clearList();

    // print again
    cout << "Printing the Empty Arrays" << endl;
    intList.print();
    stringList.print();

    // display the list size
    cout << "Printing the Size of intList and stringList" << endl;
    cout << "intList Size: " << intList.listSize() << endl;
    cout << "strintList Size: " << stringList.listSize() << endl;

    return 0;
}