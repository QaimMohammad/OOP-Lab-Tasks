#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float getArea() override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle rect(5, 3);
    Triangle tri(4, 6);

    Shape* shape1 = &rect;
    Shape* shape2 = &tri;

    cout << "Area of Rectangle: " << shape1->getArea() << endl;
    cout << "Area of Triangle: " << shape2->getArea() << endl;

    return 0;
}

