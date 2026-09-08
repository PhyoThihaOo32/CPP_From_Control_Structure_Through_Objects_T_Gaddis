#include <iostream>

// function prototype
int add(int, int);
int multiply(int ,int);
int calc(int, int, int(*)(int,int)); // pointer to a function that takes two int arguments and returns an int

using namespace std;

int main(){
    
    cout << "Calling Add Function: " << add(2,2) << endl;
    cout << "Calling Calc Function(Add): " << calc(2,2,add) << endl;
    cout << "Calling Calc Function(Multiply): " << calc(2,3,multiply) << endl;

    return 0;
}

int add(int num1, int num2){
    return (num1 + num2);
}

int multiply(int num1, int num2){
    return (num1 * num2);
}

int calc(int num1, int num2, int(*operation)(int, int )){
    return operation(num1, num2);
}