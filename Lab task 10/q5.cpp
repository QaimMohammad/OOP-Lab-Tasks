#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void addTask(const string& task) {
    ofstream out("todo.txt", ios::app);
    out << task << ",0\n";
    out.close();
}

void viewTasks() {
    ifstream in("todo.txt");
    string line;
    int i = 1;
    while (getline(in, line)) {
        size_t comma = line.find(',');
        string task = line.substr(0, comma);
        string done = line.substr(comma + 1);
        cout << i++ << ". " << task << (done == "1" ? " [Done]" : "") << "\n";
    }
    in.close();
}

void markDone(int index) {
    ifstream in("todo.txt");
    vector<string> lines;
    string line;
    while (getline(in, line)) lines.push_back(line);
    in.close();

    if (index >= 1 && index <= lines.size()) {
        size_t comma = lines[index - 1].find(',');
        lines[index - 1] = lines[index - 1].substr(0, comma) + ",1";
    }

    ofstream out("todo.txt");
    for (auto& l : lines) out << l << "\n";
    out.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Done\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string task;
            cout << "Enter Task: ";
            getline(cin, task);
            addTask(task);
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            int num;
            cout << "Enter Task Number: ";
            cin >> num;
            markDone(num);
        } else break;
    }
    return 0;
}

