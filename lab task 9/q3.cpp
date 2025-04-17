#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    float salary;
public:
    virtual void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displayData() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual void bonus() {
        cout << "Bonus: " << salary * 0.10 << endl;
    }
};

class Admin : public Person {
public:
    void bonus() override {
        cout << "Admin Bonus: " << salary * 0.15 << endl;
    }
};

class Account : public Person {
public:
    void bonus() override {
        cout << "Account Bonus: " << salary * 0.12 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayData() override {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    void bonus() override {
        cout << "Master Bonus: " << salary * 0.20 << endl;
    }

private:
    using Person::name;
    using Person::id;
    using Person::salary;
};

int main() {
    Person* ptr;

    Admin a;
    cout << "--- Admin Details ---" << endl;
    ptr = &a;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << endl;

    Account acc;
    cout << "--- Account Details ---" << endl;
    ptr = &acc;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << endl;

    Master m;
    cout << "--- Master Details ---" << endl;
    ptr = (Person*)&m;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    return 0;
}

