#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v) : value(v) {}

    // Prefix operator overloading (multiplying by 4)
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix operator overloading (dividing by 4)
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(10);
    
    --num;  // Prefix
    num.display();

    num--;  // Postfix
    num.display();

    return 0;
}


