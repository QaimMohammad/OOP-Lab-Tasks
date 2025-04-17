#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    void setModel(string m) {
        model = m;
    }

    string getModel() {
        return model;
    }

    float getPrice() {
        return price;
    }

    virtual void setPrice(float p) = 0;
};

class Color : public Car {
private:
    string color;
public:
    void setColor(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    void setPrice(float p) override {
        price = p;
    }
};

class Company : public Car {
private:
    string companyName;
public:
    void setCompany(string c) {
        companyName = c;
    }

    string getCompany() {
        return companyName;
    }

    void setPrice(float p) override {
        price = p;
    }
};

int main() {
    Color c1;
    c1.setModel("Sedan");
    c1.setColor("Red");
    c1.setPrice(25000);

    Company c2;
    c2.setModel("SUV");
    c2.setCompany("Toyota");
    c2.setPrice(35000);

    cout << "Color Object Info:" << endl;
    cout << "Model: " << c1.getModel() << endl;
    cout << "Color: " << c1.getColor() << endl;
    cout << "Price: $" << c1.getPrice() << endl;

    cout << "\nCompany Object Info:" << endl;
    cout << "Model: " << c2.getModel() << endl;
    cout << "Company: " << c2.getCompany() << endl;
    cout << "Price: $" << c2.getPrice() << endl;

    return 0;
}

