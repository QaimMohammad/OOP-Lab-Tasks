#include <iostream>
using namespace std;

class Student {
public:
    const int roll_no;

    Student() : roll_no(0) {}

    void setRollNo(int roll) const {
        const_cast<Student*>(this)->roll_no = roll;
    }

    void displayRollNo() const {
        cout << "Roll Number: " << roll_no << endl;
    }
};

int main() {
    Student student;
    int roll;
    cout << "Enter student roll number: ";
    cin >> roll;
    
    student.setRollNo(roll);
    student.displayRollNo();
    return 0;
}

