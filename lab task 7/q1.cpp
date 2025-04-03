#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, double bal, string holder, string type) 
        : accountNumber(accNum), balance(bal), accountHolderName(holder), accountType(type) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual double calculateInterest() = 0;
    virtual void printStatement() = 0;
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string holder, double rate, double minBal) 
        : Account(accNum, bal, holder, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override {
        return balance * interestRate / 100;
    }

    void printStatement() override {
        cout << "Savings Account - " << accountHolderName << " | Balance: " << balance << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int accNum, double bal, string holder, double rate, int maturity) 
        : Account(accNum, bal, holder, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() override {
        return balance * fixedInterestRate / 100;
    }

    void printStatement() override {
        cout << "Fixed Deposit - " << accountHolderName << " | Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount sa(101, 5000, "John Doe", 3.5, 1000);
    FixedDepositAccount fda(102, 10000, "Jane Smith", 5.0, 2027);

    sa.deposit(1000);
    sa.withdraw(2000);
    sa.printStatement();

    fda.printStatement();
    cout << "Fixed Deposit Interest: " << fda.calculateInterest() << endl;

    return 0;
}

