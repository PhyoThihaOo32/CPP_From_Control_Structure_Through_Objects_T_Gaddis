#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accNumber;
    double balance;

public:
    BankAccount(int accNumber, double balance) : accNumber(accNumber), balance(balance)
    {
    }

    BankAccount(const BankAccount &bk)
    {
        accNumber = bk.accNumber;
        balance = bk.balance;
    }

    int getAccNumber() const
    {
        return accNumber;
    }

    double getBalance() const { return balance; }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        balance -= amount;
    }
};

class PersonInfo
{
private:
    BankAccount citiAccount;
    BankAccount independenceAccount;
    string ssn;

    /*
      Write a constructor which initializes the citiAccount, the independenceAccount and the ssn.
      The constructor receives a String parameter to initialize the ssn, a BankAccount object to
      pass to the BankAccount copy constructor when creating the citiAccount object, and a
      BankAccount object to pass to the BankAccount copy constructor when creating the
      independenceAccount object.
   */
public:
    PersonInfo(string ssn, const BankAccount &citi, const BankAccount &independenceAcc) : ssn(ssn), citiAccount(citi), independenceAccount(independenceAcc)
    {
    }
};

/*
From the BankAccount class defined in question 2, derive a class named SavingsAccount having
an additional data member named monthInterestRate, a constructor with three parameters ( one
for the monthInterestRate and two for the constructor of BankAccount) , and a calcInterest
method  that returns the monthly interest on the account – the monthly interest is: balance *
monthInterestRate.
*/

class SavingsAccount : public BankAccount
{
private:
    double monthInterestRate;

public:
    SavingsAccount(double interestRate, int accountNumber, double balance) : monthInterestRate(interestRate), BankAccount(accountNumber, balance)
    {
    }

    double calcIntereset() const
    {
        return monthInterestRate * getBalance();
    }
};