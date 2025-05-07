#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() {
        return M_PI * radius * radius;
    }

    double getPerimeter() {
        return 2 * M_PI * radius;
    }
};

int main() {
    double radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;

    Circle circle(radius);
    cout << "Area: " << circle.getArea() << endl;
    cout << "Perimeter: " << circle.getPerimeter() << endl;

    return 0;
}


