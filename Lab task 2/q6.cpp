#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    string subject_name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    vector<Student> students;
    int numStudents = 3;

    // Creating dynamic array of students with subjects
    for (int i = 0; i < numStudents; i++) {
        Student student;
        student.id = i + 1;
        int numSubjects;
        cout << "Enter the number of subjects for student " << student.id << ": ";
        cin >> numSubjects;

        for (int j = 0; j < numSubjects; j++) {
            Subject subject;
            cout << "Enter subject " << j + 1 << ": ";
            cin >> subject.subject_name;
            student.subjects.push_back(subject);
        }

        students.push_back(student);
    }

    // Printing student data with subjects
    for (const auto& student : students) {
        cout << "\nStudent ID: " << student.id << endl;
        for (const auto& subject : student.subjects) {
            cout << "Subject: " << subject.subject_name << endl;
        }
    }

    return 0;
}

