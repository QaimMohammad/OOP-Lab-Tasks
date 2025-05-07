#include <iostream>
#include <any>
#include <stdexcept>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Type mismatch!";
    }
};

class TypeSafeContainer {
    any data;
public:
    template <typename T>
    void store(const T& value) {
        data = value;
    }

    template <typename T>
    T get() {
        if (!data.has_value()) throw BadTypeException();
        try {
            return any_cast<T>(data);
        } catch (const bad_any_cast&) {
            throw BadTypeException();
        }
    }
};

int main() {
    TypeSafeContainer c;
    c.store<int>(10);
    try {
        cout << c.get<int>() << "\n";
        cout << c.get<float>() << "\n"; // throws
    } catch (const BadTypeException& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}

