/*
PQ2: Consider the following simple class:

     class BankAccount
       {
           private:
                  int accNumber;
                  double balance;
           public:
                  BankAccount ( int, double );
                  int getAccNumber ();
                  double getBalance();
                  void deposit ( double amount ){ balance += amount; }
                  void withdraw ( double amount ) { balance -= amount; }
       };

Consider the following class that uses the BankAccount class defined in question 2 :

      class PersonInfo
       {
          private:
             BankAccount citiAccount;
             BankAccount independenceAccount;
             String ssn;
           …

        };

Write a constructor which initializes the citiAccount, the independenceAccount and the ssn.
The constructor receives a String parameter to initialize the ssn, a BankAccount object to
pass to the BankAccount copy constructor when creating the citiAccount object, and a
BankAccount object to pass to the BankAccount copy constructor when creating the
independenceAccount object.


*/

#include <iostream>
#include <string>

using namespace std;

/*
=========================================================
BankAccount Class
=========================================================
*/

class BankAccount
{
private:
    int accNumber;
    double balance;

public:
    // Parameterized constructor
    BankAccount(int accNum, double bal)
    {
        accNumber = accNum;
        balance = bal;
    }

    // Copy constructor
    BankAccount(const BankAccount &acc)
    {
        accNumber = acc.accNumber;
        balance = acc.balance;
    }

    int getAccNumber()
    {
        return accNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        balance -= amount;
    }
};

/*
=========================================================
PersonInfo Class (Aggregation + Copy Constructor Use)
=========================================================
*/

class PersonInfo
{
private:
    BankAccount citiAccount;
    BankAccount independenceAccount;
    string ssn;

public:
    // Constructor using initializer list (IMPORTANT)
    PersonInfo(string s, BankAccount citi, BankAccount indep)
        : ssn(s), citiAccount(citi), independenceAccount(indep)
    {
    }

    void display()
    {
        cout << "SSN: " << ssn << endl;
        cout << "Citi Account: " << citiAccount.getAccNumber()
             << " Balance: " << citiAccount.getBalance() << endl;
        cout << "Independence Account: " << independenceAccount.getAccNumber()
             << " Balance: " << independenceAccount.getBalance() << endl;
    }
};

/*
=========================================================
Main Function (Test)
=========================================================
*/

int main()
{
    BankAccount acc1(1001, 5000.0);
    BankAccount acc2(2002, 3000.0);

    PersonInfo person("123-45-6789", acc1, acc2);

    person.display();

    return 0;
}