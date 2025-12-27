#include "BankAccount.h"

// Constructor
Account::Account(double bal, double iRate)
{
    balance = bal;
    interestRate = iRate;
    interest = 0.0;
    nTransactions = 0;
}

// Set interest rate
void Account::setInterestRate(double rate)
{
    if (rate >= 0)
        interestRate = rate;
}

// Deposit
void Account::makeDeposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        nTransactions++;
    }
}

// Withdraw
bool Account::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        nTransactions++;
        return true;
    }
    return false;
}

// Calculate and add interest to balance
void Account::addInterest()
{
    interest = balance * interestRate;
    balance += interest;
}

// Getters
double Account::getInterestRate() const { return interestRate; }
double Account::getBalance() const { return balance; }
double Account::getInterest() const { return interest; }
int Account::getTransactions() const { return nTransactions; }