#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    Account account(1000.0);

    account.credit(500.0);
    cout << "Current balance: " << account.getBalance() << endl;

    account.debit(200.0);
    cout << "Current balance: " << account.getBalance() << endl;

    account.debit(2000.0);  // Trying to debit more than available balance
    cout << "Current balance: " << account.getBalance() << endl;

    return 0;
}

