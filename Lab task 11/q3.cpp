#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds!";
    }
};

template <typename T>
class SafeArray {
    T* arr;
    int size;
public:
    SafeArray(int s) : size(s) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }
};

int main() {
    SafeArray<int> sa(5);
    try {
        sa[0] = 10;
        sa[1] = 20;
        cout << sa[1] << "\n";
        cout << sa[10] << "\n"; // will throw
    } catch (const ArrayIndexOutOfBounds& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}

