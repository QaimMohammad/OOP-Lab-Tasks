#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;
public:
    void getData(int id) {
        employeeID = id;
    }

    void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    float monthlyIncome;
public:
    void getData(string n, float income, int id) {
        name = n;
        monthlyIncome = income;
        Person::getData(id);
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
    }

    float bonus() {
        return monthlyIncome * 0.05;  // 5% bonus
    }
};

class Accounts : public Person {
protected:
    string name;
    float monthlyIncome;
public:
    void getData(string n, float income, int id) {
        name = n;
        monthlyIncome = income;
        Person::getData(id);
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
    }

    float bonus() {
        return monthlyIncome * 0.05;  // 5% bonus
    }
};

int main() {
    Admin admin;
    Accounts account;
    
    admin.getData("Alice", 5000, 101);
    account.getData("Bob", 4000, 102);

    cout << "\nAdmin Details:\n";
    admin.displayData();
    cout << "Bonus: " << admin.bonus() << endl;

    cout << "\nAccounts Details:\n";
    account.displayData();
    cout << "Bonus: " << account.bonus() << endl;

    return 0;
}

