#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string position;
    string color;
    double borderThickness;

public:
    Shape(string pos, string col, double border) 
        : position(pos), color(col), borderThickness(border) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string pos, string col, double border, double r) 
        : Shape(pos, col, border), radius(r) {}

    void draw() override {
        cout << "Drawing Circle at " << position << " with color " << color << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string pos, string col, double border, double w, double h) 
        : Shape(pos, col, border), width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle at " << position << " with color " << color << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

int main() {
    Circle c("center", "red", 2.0, 5.0);
    Rectangle r("top-left", "blue", 1.5, 4.0, 6.0);

    c.draw();
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Circle Perimeter: " << c.calculatePerimeter() << endl;

    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl;

    return 0;
}

