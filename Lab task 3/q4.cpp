#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    // Constructor
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        monthlySalary = (salary > 0) ? salary : 0.0;
    }

    // Method to get the yearly salary
    double getYearlySalary() {
        return monthlySalary * 12;
    }

    // Method to give a 10% raise
    void applyRaise() {
        monthlySalary += monthlySalary * 0.10;
    }

    // Method to display employee information
    void displayEmployeeInfo() {
        cout << "Employee: " << firstName << " " << lastName << endl;
        cout << "Yearly Salary: $" << getYearlySalary() << endl;
    }
};

int main() {
    Employee employee1("John", "Doe", 3000);
    Employee employee2("Jane", "Smith", 4000);

    cout << "Before Raise:" << endl;
    employee1.displayEmployeeInfo();
    employee2.displayEmployeeInfo();

    // Apply raise
    employee1.applyRaise();
    employee2.applyRaise();

    cout << "\nAfter 10% Raise:" << endl;
    employee1.displayEmployeeInfo();
    employee2.displayEmployeeInfo();

    return 0;
}

