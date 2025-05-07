#include <iostream>
using namespace std;

class student {
    int id;
    string name;
public:
    void getstudentdetails() {
        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
    }

    void displaystudentdetails() {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};

class marks : public student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;
public:
    void getmarks() {
        cout << "Enter marks for OOP: ";
        cin >> marks_oop;
        cout << "Enter marks for PF: ";
        cin >> marks_pf;
        cout << "Enter marks for DS: ";
        cin >> marks_ds;
        cout << "Enter marks for DB: ";
        cin >> marks_db;
    }

    void displaymarks() {
        cout << "Marks in OOP: " << marks_oop << endl;
        cout << "Marks in PF: " << marks_pf << endl;
        cout << "Marks in DS: " << marks_ds << endl;
        cout << "Marks in DB: " << marks_db << endl;
    }
};

class result : public marks {
protected:
    int total_marks;
    double avg_marks;
public:
    void display() {
        total_marks = marks_oop + marks_pf + marks_ds + marks_db;
        avg_marks = total_marks / 4.0;
        cout << "Total Marks: " << total_marks << endl;
        cout << "Average Marks: " << avg_marks << endl;
    }
};

int main() {
    result r;
    r.getstudentdetails();
    r.getmarks();

    cout << endl << "--- Student Details ---" << endl;
    r.displaystudentdetails();

    cout << endl << "--- Marks Obtained ---" << endl;
    r.displaymarks();

    cout << endl << "--- Result ---" << endl;
    r.display();

    return 0;
}

