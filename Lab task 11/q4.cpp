#include <iostream>

using namespace std;

template <typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    void printProduct() {
        cout << "Base Product: " << a * b << "\n";
    }
};

template <typename T>
class Derived : public Base<T> {
    T c, d;
public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}
    void printDerivedProduct() {
        cout << "Derived Product: " << c * d << "\n";
    }
};

int main() {
    Derived<int> d(2, 3, 4, 5);
    d.printProduct();
    d.printDerivedProduct();
    return 0;
}

