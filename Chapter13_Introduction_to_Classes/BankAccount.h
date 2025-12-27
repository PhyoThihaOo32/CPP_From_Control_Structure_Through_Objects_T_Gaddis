#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class Account
{
private:
    double balance;
    double interestRate;
    double interest;
    int nTransactions;

public:
    // Constructor with default values
    Account(double bal = 0.0, double iRate = 0.045);

    // Mutators
    void setInterestRate(double);
    void makeDeposit(double);
    bool withdraw(double);
    void addInterest();

    // Accessors
    double getInterestRate() const;
    double getBalance() const;
    double getInterest() const;
    int getTransactions() const;
};

#endif