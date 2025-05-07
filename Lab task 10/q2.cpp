#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years;
};

Employee parseLine(const string& line) {
    stringstream ss(line);
    string temp;
    Employee emp;
    getline(ss, temp, ',');
    emp.id = stoi(temp);
    getline(ss, emp.name, ',');
    getline(ss, emp.designation, ',');
    getline(ss, temp);
    emp.years = stoi(temp);
    return emp;
}

void writeToFile(const vector<Employee>& list, const string& filename) {
    ofstream out(filename);
    for (const auto& emp : list) {
        out << emp.id << "," << emp.name << "," << emp.designation << "," << emp.years << "\n";
    }
    out.close();
}

int main() {
    ifstream file("data.txt");
    string line;
    vector<Employee> allEmployees;

    while (getline(file, line)) {
        allEmployees.push_back(parseLine(line));
    }
    file.close();

    vector<Employee> queryResult;
    for (auto& emp : allEmployees) {
        if (emp.designation == "Manager" && emp.years >= 2)
            queryResult.push_back(emp);
    }

    cout << "Query Result:\n";
    for (auto& emp : queryResult)
        cout << emp.id << " " << emp.name << " " << emp.designation << " " << emp.years << "\n";

    writeToFile(queryResult, "data.txt");

    for (auto& emp : queryResult) {
        emp.id += 10;
        emp.years += 1;
    }
    writeToFile(queryResult, "updated_data.txt");
    cout << "Updated data written to updated_data.txt\n";

    return 0;
}


