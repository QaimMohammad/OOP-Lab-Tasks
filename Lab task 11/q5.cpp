#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack is empty!";
    }
};

template <typename T>
class Stack {
    vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (elements.empty())
            throw StackUnderflowException();
        elements.pop_back();
    }

    T top() {
        if (elements.empty())
            throw StackUnderflowException();
        return elements.back();
    }

    bool empty() {
        return elements.empty();
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        cout << "Top: " << s.top() << "\n";
        s.pop();
        s.pop();
        s.pop(); // will throw
    } catch (const StackUnderflowException& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}

