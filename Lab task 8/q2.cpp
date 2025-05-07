#include <iostream>
using namespace std;

class Shape {
    float area;
public:
    Shape(float a = 0) : area(a) {}

    float Area() {
        return area;
    }

    // Overload + operator to add areas
    float operator+(Shape& other) {
        return this->area + other.area;
    }
};

int main() {
    Shape shape1(50), shape2(30);
    float totalArea = shape1 + shape2;  // Adding areas using overloaded operator
    cout << "Total Area: " << totalArea << endl;
    return 0;
}


