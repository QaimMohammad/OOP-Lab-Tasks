#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {
    int id;
    string name;
};

// Comparator function to sort by ID and then by the first character of name
bool compare(Employee a, Employee b) {
    if (a.id == b.id) {
        return a.name[0] < b.name[0];
    }
    return a.id < b.id;
}

int main() {
    vector<Employee> employees = {
        {3, "John"},
        {2, "Alice"},
        {1, "Bob"},
        {3, "Charlie"},
        {2, "David"}
    };

    // Sorting by ID and then by name's first character
    sort(employees.begin(), employees.end(), compare);

    cout << "Sorted by ID and name: " << endl;
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << endl;
    }

    // Sorting by Name
    sort(employees.begin(), employees.end(), [](Employee a, Employee b) {
        return a.name < b.name;
    });

    cout << "\nSorted by Name: " << endl;
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << endl;
    }

    return 0;
}


