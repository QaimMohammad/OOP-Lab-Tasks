#include <iostream>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    double salary;
};

struct Organisation {
    string organisation_name;
    string organisation_number;
    Employee emp;  // Nested structure

    void displayData() {
        cout << "Organisation Name: " << organisation_name << endl;
        cout << "Organisation Number: " << organisation_number << endl;
        cout << "Employee ID: " << emp.employee_id << endl;
        cout << "Employee Name: " << emp.name << endl;
        cout << "Employee Salary: " << emp.salary << endl;
    }
};

int main() {
    Organisation org;

    // Assign values to the Organisation and Employee structures
    org.organisation_name = "NU-Fast";
    org.organisation_number = "NUFAST123ABC";
    org.emp.employee_id = 127;
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;

    cout << "Size of structure organisation: " << sizeof(org) << endl;
    org.displayData();

    return 0;
}

