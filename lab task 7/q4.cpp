#include <iostream>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << endl;
    }
};

class Student : public Person {
private:
    int coursesEnrolled, enrollmentYear;
    double GPA;

public:
    Student(string n, string i, string a, string p, string e, int courses, double g, int year)
        : Person(n, i, a, p, e), coursesEnrolled(courses), GPA(g), enrollmentYear(year) {}

    void displayInfo() override {
        cout << "Student | " << name << " | GPA: " << GPA << " | Year: " << enrollmentYear << endl;
    }

    double getGPA() {
        return GPA;
    }
};

class Professor : public Person {
private:
    string department;
    int coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string p, string e, string dept, int courses, double sal)
        : Person(n, i, a, p, e), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        cout << "Professor | " << name << " | Department: " << department << " | Salary: " << salary << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string dept, string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        cout << "Staff | " << name << " | Position: " << position << " | Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor;
    int credits;
    string schedule;

public:
    Course(string id, string name, string inst, int cr, string sch)
        : courseId(id), courseName(name), instructor(inst), credits(cr), schedule(sch) {}

    void registerStudent(Student s) {
        cout << s.name << " registered for " << courseName << endl;
    }

    void calculateGrades(Student s) {
        if (s.getGPA() >= 3.5)
            cout << s.name << " gets an A in " << courseName << endl;
        else if (s.getGPA() >= 3.0)
            cout << s.name << " gets a B in " << courseName << endl;
        else if (s.getGPA() >= 2.5)
            cout << s.name << " gets a C in " << courseName << endl;
        else
            cout << s.name << " gets an F in " << courseName << endl;
    }
};

int main() {
    Student s1("Alice", "S101", "123 St", "555-1234", "alice@mail.com", 5, 3.8, 2022);
    Professor p1("Dr. Bob", "P201", "456 St", "555-5678", "bob@mail.com", "Math", 3, 75000);
    Staff staff1("Charlie", "ST301", "789 St", "555-9876", "charlie@mail.com", "Admin", "Manager", 50000);
    Course c1("CSE101", "Intro to Programming", "Dr. Bob", 3, "Mon-Wed 10 AM");

    s1.displayInfo();
    p1.displayInfo();
    staff1.displayInfo();
    c1.registerStudent(s1);
    c1.calculateGrades(s1);

    return 0;
}

